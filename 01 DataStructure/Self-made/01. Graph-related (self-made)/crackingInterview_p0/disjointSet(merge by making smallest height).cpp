#include <fstream> //for fout, fin
#include <iostream> //for cout, cin

#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <numeric>
#include <utility> //for pair
#include <functional> //for greater<>

#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii; // Creating shortcut for an integer pair
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
#define sync ios::sync_with_stdio(false); cin.tie(nullptr); cout.precision(10);
#define _CRT_SECURE_NO_WARNINGS

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int MOD = (int)1000000007;
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

//represent Disjoint Sets
struct disjointSets
{

	int *parent, *height;
	int n; //the number of nodes in whole disjoint sets.
	int cnt; //the number of disjoint sets.

	disjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		cnt = n;
		parent = new int[n + 1]; //parent of each node
		height = new int[n + 1]; //height of tree when root node is n

								 // Initially, all vertices are in different sets and have height 0.
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i; //every element is parent of itself at first.
		}
	}

	~disjointSets() {
		delete parent;
		delete height;
	}

	// Find the parent of a node 'u' 
	int find(int u)
	{
		int result = parent[u];
		//Make the parent of the nodes in the path from u--> parent[u] point to parent[u]
		if (u != parent[u])
			result = find(parent[u]);
		return result;


	}

	// Union by making tree with smaller height a subtree of the other tree 
	void merge(int x, int y)
	{
		x = find(x), y = find(y);


		if (height[x] > height[y])
			parent[y] = x;
		else if (height[x] < height[y])
			parent[x] = y;
		else
		{
			// ** self-defined rule **
			// second argument(x) becomes parent of first argument(y)
			// in line 58 and 59, variable x ,y can be interchangeable.
			parent[x] = y;
			height[y]++;
		}
		cnt--; //decrease the number of disjoint sets.
	}

	// Are objects x and y in the same set?
	bool connected(int x, int y) {
		return find(x) == find(y);
	}

	// Return the number of disjoint sets.
	int count() {
		return cnt;
	}

};