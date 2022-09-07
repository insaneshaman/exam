#include "Header.h"

bool check(const string S1, const string S2)
{
	if (S1.find(S2, 0) == 4294967295) return false;

	else return true;
}

int finder(const string S1or, const string S2)
{
	string S1 = S1or;

	if (!check(S1, S2)) return -1;

	int count = 0;

	for (; 0 < S1.size(); count++) S1.erase(0, S1.find(S2, 0) + S2.size());

	return count;
}