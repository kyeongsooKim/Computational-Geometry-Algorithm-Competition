
#include <vector>
#include <iostream>
#include <numeric> // std::accumulate


using namespace std;


/*if you take a ^ a, you will always get 0. Furthermore, if you take a ^ x ^ a,
you will always get x.Therefore, all the pairs of numbers will cancel out.
For example, if you have n = 9 and A = { 4, 9, 95, 93, 57, 4, 57, 93, 9 },
then you will effectively by computing the value of 4 ^ 9 ^ 95 ^ 93 ^ 57 ^ 4 ^ 57 ^ 93 ^ 9.
It doesn't matter what order you take the xors, so this is equivalent to
(4 ^ 4) ^ (9 ^ 9) ^ (95) ^ (93 ^ 93) ^ (57 ^ 57), which is 0 ^ 0 ^ 95 ^ 0 ^ 0, or just 95. */

int lonelyinteger(vector <int> a) {
	int result = 0;
	for (int i = 0; i< a.size(); i++)
		result ^= a[i];
	return result;


}

//lambda expression
int lonelyinteger2(vector <int> a) {
	return accumulate(a.begin(), a.end(), 0, [](int k, int i) { return k ^ i; });
}


int main() {
	int n;
	cin >> n;


	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	int result = lonelyinteger(a);
	cout << result << endl;
	return 0;
}