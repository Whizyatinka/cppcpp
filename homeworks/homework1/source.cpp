#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x, y;
	cin >> x >> y;
	float R = cos(3.14159265 / 4 * x) / sin(3.14159265 / 4 * x);
	float S = sqrt(sqrt(y)) * pow(2, 1 / y);
	cout << R << ' ' << S;
	return 0;
}
