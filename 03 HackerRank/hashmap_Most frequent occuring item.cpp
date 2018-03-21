//Most Frequent Occuring Item

#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map> //hashmap
#include <iostream> //cout
#include <string> //string object , getline()

using namespace std;

int main()
{

	string str;
	getline(cin, str);

	unordered_map<int, int> map;

	int n = atoi(strtok((char*)str.c_str(), " "));


	getline(cin, str);
	int max_item, max_count, key;

	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			key = atoi(strtok((char*)str.c_str(), " "));
			max_item = key; //init
			max_count = 1; //init
		}
		else
			key = atoi(strtok(NULL, " "));

		if (map.find(key) == map.end())
			map[key] = 1;
		else
			map[key]++;

		if (map[key] >= max_count)
		{
			max_item = key;
			max_count = map[key];
		}
	}

	cout << max_item;
	unordered_map<int, int>::iterator itr;
	cout << "\nAll Elements : " << endl;
	for (itr = map.begin(); itr != map.end(); itr++)
	{
		cout << "key : " << itr->first << ", value : " << itr->second << endl;
	}


	return 0;
}