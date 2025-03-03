#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double D, H, W;
	cin >> D >> H >> W;

	double x = pow((D * D) / (H * H + W * W), 0.5);
	cout << int(H * x) << ' ' << int(W * x);
	return 0;
}