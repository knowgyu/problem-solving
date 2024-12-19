#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int M, A, B;
		cin >> M >> A >> B;
		if (!M && !A && !B) break;

		double train = (double)M / A;
		double plane = (double)M / B;

		double diff = abs(train - plane);
		
		int sec = round(diff * 3600);

		int H = sec / 3600;
		int MM = (sec % 3600) / 60;
		int SS = (sec % 3600) % 60;

		printf("%d:%02d:%02d\n", H, MM, SS);
	}


	return 0;
}
