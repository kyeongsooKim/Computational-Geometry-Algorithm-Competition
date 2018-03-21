
//Most Frequent Occuring Item

#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map> //hashmap
#include <iostream> //cout
#include <string> //string object , getline()

using namespace std;




typedef pair<int, int> pii;

bool heap_util(pii a, pii b) { return (a.first > b.first); }

bool sort_util(int i, int j) { return (i < j); }

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

		for (int num : nums){
			map[num]++;
		}
        

        // pair<first, second>: first is frequency,  second is number
        priority_queue<pii, vector<pii>, heap_util> min_heap;
		
        for(auto it = map.begin(); it != map.end(); it++){
            min_heap.push(make_pair(it->second, it->first));
            if(k < min_heap.size())
                min_heap.pop();
        }
		// now heap hold the elements that elements less than them are all removed.
        
		vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

		sort(res.begin(),res.end());

        return res;
    }
};

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
			map.insert(make_pair(key, 1));
		else
			map[key]++;

		if (map[key] >= max_count)
		{
			max_item = key;
			max_count = map[key];
		}
	}

	cout << max_item;

	return 0;
}