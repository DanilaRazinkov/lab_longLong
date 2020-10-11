#include <iostream>
#include <string>

using namespace std;

using namespace std;

class LongLong
{
	long* old;
	unsigned long* jun;

public:
	LongLong(long = 0, unsigned long = 0);
	LongLong(__int64);
	~LongLong();
	LongLong(const LongLong&);
	LongLong& operator=(const LongLong&);
	bool is_neg();
	ostream& operator << (ostream&);
	istream& operator>>(istream&);
	LongLong operator+(const LongLong&);
	string toString();
};