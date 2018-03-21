
#include <fstream> //for fout, fin
#include <iostream> //for cout, cin
#include <algorithm>
#include <numeric>
#include <utility> //for pair
#include <functional> //for greater<>
#include <bitset> //for std::bitset

#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <deque>
#include <map>
#include <string>

#include <cmath>
#include <ctime> //clock() , CLOCKS_PER_SEC 
#include <cassert>
#include <cstdio>
#include <cstdlib> //rand, srand
#include <cstring>
#include <stdio.h>



using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define fill(a,x) memset(a,x,sizeof(a))
#define clean(a) memset((a),0,sizeof (a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i <= (b); i++)
#define rrep(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = (b); i >= (a); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sync ios::sync_with_stdio(false); cout.precision(10); cout << fixed;
#define print_running_time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define _CRT_SECURE_NO_WARNINGS

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int MOD = (int)1000000007;
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));


#define MAXN   100005
int parent[MAXN];
int sizeOfSet[MAXN];
//int cnt; //when we need to check the number of disjoint sets.

void init(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		parent[i] = i;
		sizeOfSet[i] = 1;
	}
}

// Find the parent of a node 'u' 
int find(int u)
{
	//Make the parent of the nodes in the path from u--> parent[u] point to parent[u]
	if (u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u];
	
}


// compared to find1 O(2N), find2 has O(3N) time complexity, when N is the number of 
// this recursive function call. Basically O(2N) = O(3N), but for competitive coding test,
// this small difference could matter when input data gets larger.
// In this example, when we read input2 (when node is 1000~50000)
// the time difference between those around are 0.2 second. But (when node is more than
// 100000) find takes 25 seconds, but find2 doesn't work at all. (timeout)
/*
int find2(int u)
{
	int result = parent[u];
	if (u != parent[u])
		result = find2(parent[u]);
	return result;
}
*/


void merge(int u, int v)
{
	int x = find(u);
	int y = find(v);

	if (x == y) return;


	parent[x] = y;     	// updating the parentent of the new component
	sizeOfSet[y] += sizeOfSet[x]; // updating the size of the new component
	//cnt--; //decrease the number of disjoint sets.
}

bool connected(int x, int y) {
	return find(x) == find(y);
}

int main()
{
	sync
	ifstream fin("input.txt");
	string str;
	getline(fin, str);

	int n, q;
	n = atoi(strtok((char*)str.c_str(), " "));
	q = atoi(strtok(NULL, " "));
	init(n);

	rep2(i, 1, q)
	{
		getline(fin, str);
		char ch;

		//*****caution****** we are getting char, not int!!!! no need to use atoi!!!!
		ch = strtok((char*)str.c_str(), " ")[0]; 
		
		int u, v, idx;
		if (ch == 'Q')
		{
			idx = atoi(strtok(NULL, " "));
			printf("%d\n", sizeOfSet[find(idx)]);
		}
		else
		{
			u = atoi(strtok(NULL, " "));
			v = atoi(strtok(NULL, " "));
			merge(u, v);
		}
	}

	fin.close();
	print_running_time
	return 0;
}

