#include <bits/stdc++.h>
using namespace std;

int main()
{
	int bi, bj, di, dj, ji, jj;
	cin >> bi >> bj >> di >> dj >> ji >> jj;

	int daisy = abs(di - ji) + abs(dj - jj);
	int bessie = max(abs(bj - jj), abs(bi - ji));

	if (daisy > bessie)
		cout << "bessie";
	else if (daisy < bessie)
		cout << "daisy";
	else
		cout << "tie";

	return 0;
}