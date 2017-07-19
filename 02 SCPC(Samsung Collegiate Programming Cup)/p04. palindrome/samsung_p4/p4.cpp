#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
#include <queue>
using namespace std;

struct LongerSize //customized operator : longer string = bigger
{
	bool operator()(const string str1, const string str2) const
	{
		return str1.size() > str2.size();
	}
};

void takePalindromes(string str, priority_queue<string, vector<string>, LongerSize>* palindromes) {
	for (int i = 1; i < str.size() - 1; i++) {
		
		//when palindrome has odd characters
		int j = 1;
		while (i - j >= 0 && i + j < str.size() && str[i - j] == str[i + j]) {
			string palindrome = str.substr(i - j, j*2 + 1);
			palindromes->push(palindrome);
			j++;
		}

		//when palindrome has even characters
		j = 1;
		while (i - j + 1 >= 0 && i + j < str.size() && str[i - j + 1] == str[i + j]) {
			if (j > 1) {
				string palindrome = str.substr(i - j + 1, j * 2);
				palindromes->push(palindrome);
			}
				j++;
			
		}
	}
}

void printPalindromes(priority_queue<string, vector<string>, LongerSize> pq, ofstream *fout) {
	int count = 0;
	while(!pq.empty())
	{
		cout << pq.top()<< endl;
		*fout << " " << pq.top();
		pq.pop();
		count++;
	}
	cout << "The number of palindrome : " << count << "\n\n";
	if (count > 0)
		*fout << ", " << count << endl;
	else
		*fout << " " << count << endl;
}

int main(void) {

	ofstream fout("output.txt");
	ifstream fin("input.txt");
	string str;
	//vector<string> palindromes;
	priority_queue<string, vector<string>, LongerSize> palindromes;


	getline(fin,str);
	int testNum;

	try {
		testNum = atoi(str.c_str());
		if (testNum > 7 || testNum <= 3)
			throw testNum;
	}
	catch (int e) {
		cout << "test case should be within 3 < N <= 7" << endl;
		return 0;
	}
	
	for (int i = 0; i < testNum; i++) {
		priority_queue<string, vector<string>, LongerSize> palindromes;
		getline(fin, str);
		cout << '#' << i + 1 << endl;
		fout << '#' << i + 1;

		takePalindromes(str, &palindromes);
		printPalindromes(palindromes, &fout);
	}

	fin.close();
	fout.close();

	return 0;
}

/*
void printPalindromes(vector<string> palindromes, ofstream *fout) {
vector<string>::iterator str_itr;
int count = 0;
for (str_itr = palindromes.begin(); str_itr != palindromes.end(); str_itr++)
{
cout << *str_itr << endl;
*fout << " " << *str_itr;
count++;
}
cout << "The number of palindrome : " << count<< "\n\n";
if (count > 0)
*fout << ", " << count << endl;
else
*fout << " " << count << endl;
}
*/