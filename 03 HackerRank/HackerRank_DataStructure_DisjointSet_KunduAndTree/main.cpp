#include <fstream> //fout, fin
#include <iostream> //cout, cin
#include <algorithm> //sort, max, min
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
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrep2(i, b, a) for (int i = (b); i >= (a); i--)
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
//const double PI = 3.141592653589793238463;

vi edges[100005]; //graph information
ll visited[100005]; //checking if node is visited and which set the node belongs to
ll setSize[100005];
ll B[100005], C[100005], D[100005];

void dfs(int x, int temp)
{
	if (visited[x] == 0)
		visited[x] = temp;
	for (int i = 0; i< edges[x].size(); i++)
	{
		if (visited[edges[x][i]] == 0)
			dfs(edges[x][i], temp);
	}
	return;
}

int main()
{
	sync
	fstream fin("input.txt");
	string str;
	getline(fin, str);


	int n = atoi(strtok((char*)str.c_str(), " "));

	rep(i,n-1)
	{
		getline(fin, str);
		int a = atoi(strtok((char*)str.c_str(), " "));
		int b = atoi(strtok(NULL, " "));
		char c = strtok(NULL, " ")[0];

		if (c != 'r') //assume that red edge means no edge.
		{
			edges[a].pb(b);
			edges[b].pb(a);
		}
	}

	

	int temp = 1;
	rep2(i,1,n)
	{
		if (visited[i] == 0)
		{
			dfs(i, temp);
			temp++;
		}
	}
		
	rep2(i, 1, n)
		setSize[visited[i]]++;

	ll sum = 0;
	B[n - 1] = setSize[n];
	rrep2(i, n-2, 0) B[i] = (B[i + 1] + setSize[i + 1]) % MOD;
	rep2(i, 1, n - 2) C[i] = (setSize[i + 1] * B[i + 1]) % MOD;

	D[n - 2] = C[n - 2];
	rrep2(i, n-3, 0) D[i] = (D[i + 1] + C[i]) % MOD;
	rep(i, n - 2) sum = (sum + setSize[i + 1] * D[i + 1]) % MOD;

	cout << (MOD + sum) % MOD << endl;

	fin.close();
	print_running_time
	return 0;
}
