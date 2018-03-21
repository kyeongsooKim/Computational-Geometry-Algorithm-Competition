#include <fstream> //fout, fin
#include <iostream> //cout, cin
#include <algorithm> //sort
#include <numeric>
#include <utility> //pair
#include <functional> //greater<>
#include <bitset> //std::bitset

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
#include <ctime> //clock, CLOCKS_PER_SEC 
#include <cassert>
#include <cstdio>
#include <cstdlib> //rand, srand, atoi
#include <cstring> //strtok
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


#define MAXN   30005
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

	int n;
	cin >> n;
	init(2 * n);

	rep2(i , 1, n)
	{
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	int cur_size, max = 0, min = MAXN;

	rep2(i, 1, 2*n)
	{
		cur_size = sizeOfSet[find(i)];
		if (cur_size > max) max = cur_size;
		if (cur_size > 1 && cur_size < min) min = cur_size;
	}

	cout << min << " " << max;
	return 0;
}

