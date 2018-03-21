#include <iostream>
#include <vector>

using namespace std;


//dynamic programming (bottom-up)
//time complexity : O(n) by dynamic programming.
//extra space : O(1)
int fibonacci2(int n) {
	int a = 0, b = 1, temp;

	if (n == 0)
		return a;

	//bottom up by repetition
	for (int i = 2; i <= n; i++) {
		temp = b + a;
		a = b;
		b = temp;
	}

	return b;
}




//dynamic programming (top-down)
vector<int> dp; //extra space : O(n)
				//time complexity : O(n) by dynamic programming.
int fibonacci(int n) {
	
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}



int main() {
	
	int testNum;
	cin >> testNum;

	while (testNum--) {
		int n;
		int a, b;
		cin >> n;
		dp.resize(n + 1, -1); // "dp[n] = -1" means fibonacci(n) is never called. 
		if (n == 0) {
			cout << "1 0" << endl;
		}
		else
			cout << fibonacci(n-1) << " " << fibonacci(n) << endl;
	}


	return 0;
}