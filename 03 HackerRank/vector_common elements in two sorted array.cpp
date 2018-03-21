//common_elements in two sorted array.


#define _CRT_SECURE_NO_WARNINGS

#include <vector> //hashmap
#include <iostream> //cout
#include <string> //string object , getline()
#include <algorithm>

using namespace std;

bool sort_util(int i, int j) { return (i < j); }

void init(vector<int> &A)
{
	string str;
	getline(cin, str);
	for (int i = 0; i < 6; i++)
	{
		int item;
		if (i == 0)
			item = atoi((strtok((char*)str.c_str(), " ")));
		else 
			item = atoi(strtok(NULL, " "));
		(A).push_back(item);
	}

	sort(A.begin(), A.end());

}

void printout(vector<int> &A)
{

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i];
		if (i != A.size() - 1)
			cout << ", ";
	}
	cout << endl;
}

int main()
{


	vector<int> A;
	vector<int> B;
	vector<int> solution;
	init(A);
	init(B);

	vector<int>::iterator itr1;
	vector<int>::iterator itr2;

	for (itr1 = A.begin(), itr2 = B.begin(); itr1 != A.end() && itr2 != B.end(); )
	{
		if (*itr1 == *itr2)
		{
			solution.push_back(*itr1);
			itr1++;
			itr2++;
		}
		else if (*itr1 > *itr2)
		{
			itr2++;
		}
		else
		{
			itr1++;
		}

	}

	printout(solution);

	string str;
	getline(cin, str);
	return 0;
}