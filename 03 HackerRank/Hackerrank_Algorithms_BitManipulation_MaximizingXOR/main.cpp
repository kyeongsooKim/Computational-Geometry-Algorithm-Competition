
#include <iostream>
#include <cmath>


using namespace std;

/*
	L = 10111   
	R = 11100
		_X___  <-- that's most significant differing bit
		01111  <-- here's our final answer

	For all of the lesser significant bits in A and B, we can always ensure that they
	differ and still have L <= A <= B <= R. Our final answer will be the number represented
	by all 1s starting from the most significant bit that differs between A and B
*/


static int maxXor(int l, int r) {
	int xor = l ^ r;
	int a = 0;
	while (pow(2, a)< xor)a++;
	return (int)pow(2, a) - 1;
}

int maxXor2(int a, int b) {
	int value = a ^ b, result = 1;
	while (value) {
		value = value >> 1;
		result = result << 1;
	}
	return result - 1;
}


int main() {
	int res;
	int _l;
	cin >> _l;

	int _r;
	cin >> _r;

	res = maxXor(_l, _r);
	cout << res;

	return 0;
}