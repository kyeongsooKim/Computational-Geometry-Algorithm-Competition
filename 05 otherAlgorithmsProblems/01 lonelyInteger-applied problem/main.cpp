

#include <vector>
#include <iostream>

typedef vector<int> vi;
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

vi solution(vector<vi> v) {

	int x = 0;
	int y = 0;

	rep(i, v.size()) {
		x ^= v[i][0];
		y ^= v[i][1];
	}

    vi result;
	result.push_back(x);
	result.push_back(y);
	return result;
}

int main() {

	return 0;
}