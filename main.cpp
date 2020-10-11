#include <iostream>
#include "longlong.h"

using namespace std;

int main()
{
	__int64 x = -555555555555555, y = +555555555555554;
	LongLong ll(x), l1(y);
	ll = ll + l1;
	cout << ll.toString();
	return 0;
}