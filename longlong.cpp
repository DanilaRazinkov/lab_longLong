#include <climits>
#include "longlong.h"

LongLong::LongLong(long OLD, unsigned long JUN)
{
	old = new long(OLD);
	jun = new unsigned long(JUN);
}

LongLong::LongLong(__int64 num)
{
	old = new long(long(num / 4294967296));
	jun = new unsigned long(unsigned long(num >= 0 ? num % 4294967296 : -num % 4294967296));
}

LongLong::~LongLong()
{
	delete old;
	delete jun;
}

LongLong::LongLong(const LongLong& other)
{
	old = new long(*other.old);
	jun = new unsigned long(*other.jun);
}

bool LongLong::is_neg()
{
	return (*old) < 0;
}

LongLong& LongLong::operator=(const LongLong& other)
{
	old = new long(*other.old);
	jun = new unsigned long(*other.jun);
	return *this;
}

LongLong LongLong::operator+(const LongLong& num2)
{
	LongLong op_1 = *this,
		op_2 = num2;
	unsigned long jun_res = 0;
	unsigned long jun_1 = *op_1.jun;
	unsigned long jun_2 = *op_2.jun;
	unsigned long old_res = 0;
	long old_1 = *op_1.old;
	long old_2 = *op_2.old;
	int prev = 0;
	if (op_1.is_neg()) { jun_1 = ~jun_1;jun_1--; }
	if (op_2.is_neg()) { jun_2 = ~jun_1;jun_2--; }
	for (int i = 0; i < 32; i++)
	{
		jun_res >>= 1;
		jun_res += ((((jun_1 >> i) & 1) ^ ((jun_2 >> i) & 1)) ^ prev) << 31;
		prev = (((jun_1 >> i) & 1) + ((jun_2 >> i) & 1) + prev) >= 2 ? 1 : 0;
	}

	for (int i = 0; i < 32; i++)
	{
		old_res >>= 1;
		old_res += ((((old_1 >> i) & 1) ^ ((old_2 >> i) & 1)) ^ prev) << 31;
		prev = (((old_1 >> i) & 1) + ((old_2 >> i) & 1) + prev) >= 2 ? 1 : 0;
	}
		if(prev == 1)
			jun_res = ~jun_res;


	LongLong new_num(old_res, jun_res);
	return new_num;
}

ostream& LongLong::operator<<(ostream& os)
{
	os << old << jun;
	return os;
}

istream& LongLong::operator>>(istream& is)
{
	__int64 num;
	is >> num;
	old = new long(long(num / ULONG_MAX));
	jun = new unsigned long(unsigned long(num >= 0 ? num : -num % ULONG_MAX));
	return is;
}

string LongLong::toString()
{
	if(is_neg()) return to_string(__int64((*old) * 4294967296 - *jun));
	return to_string(__int64((*old) * 4294967296 + *jun));
}