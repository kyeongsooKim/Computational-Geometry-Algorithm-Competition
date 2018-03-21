

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



int main() {

	sync
	ifstream fin("input2.txt");
	string str;
	getline(fin, str);

	int N, M;
	N = atoi(strtok((char*)str.c_str(), " "));  //N : Number of vertex
	M = atoi(strtok(NULL, " "));  //M : Number of edge

	list <int> * adj = new list<int>[N+1]; //graph information
	vector<int> deg(N + 1); //indicates how many ways there are
							//to forward to adjacent verteces from each vertices

	for (int i = 0; i < M; ++i) {
		getline(fin, str);
		int a = atoi(strtok((char*)str.c_str(), " "));
		int b = atoi(strtok(NULL, " "));

		adj[a].pb(b);
		adj[b].pb(a);

		deg[a]++;
		deg[b]++;
	}


	//solution
	int start = 1;

	int minDeg = deg[start];
	for (int i = 1; i <= N; ++i) {
		if (deg[i] < minDeg) {
			start = i;
			minDeg = deg[i];
		}
	}

	vector<int> path;
	unordered_set<int> visited;

	while (start) {
		visited.emplace(start);
		path.pb(start);
		int next = 0;
		int minDeg = N + 1;
		for (int target : adj[start]) {
			--deg[target];
			if (visited.count(target) == 0 && deg[target] < minDeg) {
				//visited.count(n) == 0    :  n is not visited yet
				//deg[target] < minDeg   :  find the next vertex which appear least in m edges given.
				minDeg = deg[target];
				next = target;
			}
		}
		start = next;
	}

	cout << path.size() << endl;
	for (int node : path) cout << node << " ";
	cout << endl;

	delete[] adj;

	#ifndef ONLINE_JUDGE
		print_running_time
	#endif

	return 0;
}


