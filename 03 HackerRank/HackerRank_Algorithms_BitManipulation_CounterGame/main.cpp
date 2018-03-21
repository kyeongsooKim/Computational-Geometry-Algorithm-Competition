#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;
typedef unsigned long long ull; // since the range of N is 1 <= N <= 2^64 - 1
								// unsigned int : when 1 <= N <= 2^32 - 1
								// int : when -2^32 <= N <= 2^31 - 1

/*

//***************    solution 1 : O(a) complexity, where a = set bits in (N-1)   *************

int my_popcnt(ull value) { //returns The number of one bits in the value parameter.
	int count = 0;	
	while (value) {
		value &= (value- 1);
		count++;
	}
	return count;
}

int my_popcnt2(ull N) { //returns The number of one bits in the value parameter.
	ull count = 0;
	while (N != 0)
	{
		if (N % 2)
			count++;
		N >>= 1;
	}
	return count;
}

// case 1 (end with 1) :  ignore last 1 through reducing it by 1
//						  count the number of 1, if it's even, Richard wins
//						  e.g) 10100 ... 1 = > 10100 ... 0
// case 2 (end with 1 + 0s) : make 1 + 0s => 0 + 1s through reducing it by 1
//						      count the number of 1, if it's even, Richard wins
//						      e.g.) 101000 => 100111

int main() {
	int testNum;
	cin >> testNum;
	while (testNum--) {
		ull n;
		cin >> n;

		if (my_popcnt(n - 1) & 1) // when my_popcnt() returns odd number
			cout << "Louise\n";
		else // when setBits() returns even number
			cout << "Richard\n";

//	*** same as line 48 to 51 ***
//		if (my_popcnt2(--n) % 2)
//			cout << "Louise" << endl;
//		else
//			cout << "Richard" << endl;
	}
	return 0;
}


*/






//***********    solution 2 : O(N) complexity but more readable and understandable    ************

#include <assert.h>

// return the msb of N
ull msb(ull n) {
	for (int idx = 63; idx >= 0; idx--) {
		if ((n & (1ll << idx)) != 0)
			return 1ll << idx;
	}
	return 0;
}

bool win(ull n) { 
	assert(n > 0);
	if (n == 1)
		return false;

	// (n & (n - 1)) : delete set-bits one by one from the right to the left
	//if n is a power of 2 ( 1 + 0s ) -> then n >> 1
	//if else, regular expression : 1(1 | 0)*10* , -> then n - msb(n)
	ull nextStep = ((n & (n - 1)) == 0 ? n >> 1 : n - msb(n)); //when 
	return !win(nextStep);
}


int main()
{
	ull num;

	int test;
	cin >> test;
	while (test--) {
		cin >> num;
		assert(num >= 1);
		cout << (win(num) ? "Louise\n" : "Richard\n");
	}



	return 0;
}
