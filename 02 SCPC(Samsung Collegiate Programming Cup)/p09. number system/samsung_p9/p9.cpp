#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> //for using reverse function
#include <math.h>

using namespace std;

int decimal2binary(int n) {
	string r;
	while (n != 0) {
		r = (n % 2 == 0 ? "0" : "1") + r;
		n /= 2;
	}
	cout << atoi(r.c_str()) << endl;
	return atoi(r.c_str());
}

string complement(int n) {
	
	string r;
	while (n != 0) {
		// concatenation of string object : str 3 = str1 + str2
		r = (n % 10 == 0 ? "1" : "0") + r; 
		n /= 10;
	}
	cout << r << endl;
	return r;
}

int binary2decimal(int bin) {
	int dec = 0;
	int p = 0;
	while (bin != 0) {
		dec += (bin % 10) * pow(2.0,p);
		bin /= 10;
		p++;
	}
	cout << dec << endl;
	return dec;
}



int my_reverse(string str) {
	reverse(str.begin(), str.end());
	cout << str << endl;
	return atoi(str.c_str());
}


int main(void) {
	ifstream fin("input.txt");

	string str;
	getline(fin, str);
	int caseNum = atoi(str.c_str());

	for (int i = 0; i < caseNum; i++) {
		getline(fin, str);
		cout << str << endl;
		int n = decimal2binary(atoi(str.c_str()));
		string s = complement(n);
		n = my_reverse(s);
		n = binary2decimal(n);
		cout << endl;
	}

	fin.close();

}