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


struct Node {
	bool isVisited;
	int value;
};


class graph {
private:
	vector<Node> node;
	list< int > * adj;
	int V;

	void visit(Node node) { //  do nothing.
	//	cout << node.value << " ";
	}

public:
	graph(int V)
	{
		this->V = V;
		adj = new list<int>[V + 1];

		vector<Node> temp(V + 1);
		node = temp;
		for (int i = 1; i < temp.size(); i++)
			node[i].value = i;
	}

	~graph() {
		delete[] adj;
	}

	int getNodeValue(int i) {
		return node[i].value;
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void resetVisited() {
		for (int i = 0; i <= V; i++)
			node[i].isVisited = false;
	}


	//Depth First Search using recursion
	void dfs2(int V)
	{
		visit(node[V]);
		node[V].isVisited = true;

		for (list<int>::iterator itr = adj[V].begin(); itr != adj[V].end(); itr++)
		{
			if (!node[*itr].isVisited)
				dfs2(*itr);
		}
	}

	void getDisjointSet(int start, queue<int> * q)
	{

		// bad example. imagine how huge time complexy would be!!!!! it doesn't even work. 
		/*
		q->push(start);
		dfs(start);	
		cout << endl;
		for (int i = start; i <= V; i++) {
			if (!node[i].isVisited) {
				getDisjointSet(i, q);
			}
		}	
		*/
		
		for (int i = 1; i <= V; i++)
		{
			if (!node[i].isVisited)
			{
				q->push(i);
				dfs2(i);
			}
		}
	}
};


int main() {

	ifstream fin("Text2.txt");
	string str;
	getline(fin, str);
	int q = atoi(str.c_str());;

	rep(i,q) {
		getline(fin, str);
		int n, m;
		ll cLib, cRoad;
		n = atoi(strtok((char*)str.c_str(), " "));
		m = atoi(strtok(NULL, " "));
		cLib = atoi(strtok(NULL, " "));
		cRoad = atoi(strtok(NULL, " "));

		graph g(n);

		rep(i, m) {
			getline(fin, str);
			int city_1 = atoi(strtok((char*)str.c_str(), " "));
			int city_2 = atoi(strtok(NULL, " "));
			g.addEdge(city_1, city_2);

		}

		queue<int> * disjointSet = new queue<int>();
		ull totalCost = 0;
		//g.getCost(&totalCost, cLib, cRoad, disjointSet);
		
		
		if (cLib > cRoad) {
			g.getDisjointSet(1, disjointSet);
			totalCost = (disjointSet->size()) * cLib
						+ (n - disjointSet->size()) * cRoad;
		}
		else {
			totalCost = cLib * n;
		}
		
		
		g.resetVisited();
		cout << totalCost <<endl;

	}

	fin.close();

	return 0;
}




//***************************  Solution from website  ***************************//
/*
vector<int> adj[100005];
bool visited[100005];
long nodes;

void DFS(int n)
{
	nodes++;
	visited[n] = true;
	for (vector<int>::iterator i = adj[n].begin(); i != adj[n].end(); i++)
	{
		if (!visited[*i])
			DFS(*i);
	}
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M, a, b;
		long X, Y;
		cin >> N >> M >> X >> Y;

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		long cost = 0;

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				nodes = 0;
				DFS(i);
				cost = cost + X;
				if (X > Y)
					cost = cost + (Y*(nodes - 1));
				else
					cost = cost + (X*(nodes - 1));
			}
		}

		cout << cost << endl;
		for (int i = 0; i <= N; i++)
		{
			adj[i].clear();
			visited[i] = false;
		}
	}

	return 0;
}
*/