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
	int n;

	disjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n + 1]; //parent of each node
		height = new int[n + 1]; //height of tree when root node is n

								 // Initially, all vertices are in different sets and have height 0.
		for (int i = 0; i <= n; i++)
		{
			height[i] = 0;

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

	}
};


struct Node {
	bool isVisited;
	int value;
};


int vertices; // for calculating how many nodes each disjoint set has.
class graph {
private:
	vector<Node> node;
	list< int > * adj;
	int V;

	void visit(Node node) { 
		vertices++; //customized function
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

	void getDisjointSet(list<pll> * li)
	{
		for (int i = 1; i <= V; i++)
		{
			if (!node[i].isVisited)
			{
				
				
				vertices = 0;
				dfs2(i);
				li->push_back(mp(i, vertices)); // put pair <root of each set, vertices of each set>

			}
		}
	}
};


int main()
{
	int i, m;
	ll n;

	cin >> n >> m;

	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}

	graph g(n);

	for (i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	list<pll> * li = new list<pll>;
	g.getDisjointSet(li);

	ull totalWays = n*(n - 1) / 2;
	ull sameWays = 0;



	for (list<pll>::iterator it = li->begin(); it != li->end(); it++) {
		sameWays = sameWays + ((it->se) * ((it->se) - 1) / 2);
	}

	cout << (totalWays - sameWays) << endl;
	return 0;
}

/******************** solution on the website ****************

#define MAX 100000


list<int> *ad;
int *visited;

void DFS(int u)
{
	visited[u] = 1;

	vertices++;

	list<int>::iterator it;

	for (it = ad[u].begin(); it != ad[u].end(); it++)
	{
		if (visited[*it] == 0)
		{
			visited[*it] = 1;
			DFS(*it);
		}
	}
}



int main()
{
	int i, m, u, v, numComponents = 0, allv = 0, temp = 2, count = 0;
	long long int n;
	int eachC[MAX];

	cin >> n >> m;

	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}

	ad = new list<int>[n];

	list<int>::iterator it;

	for (i = 0; i<m; i++)
	{
		cin >> u >> v;

		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	visited = new int[n];

	for (i = 0; i<n; i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i<n; i++)
	{
		if (visited[i] == 0)
		{
			vertices = 0;
			DFS(i);
			eachC[numComponents] = vertices;
			numComponents++;
		}
	}

	long long int totalWays = n*(n - 1) / 2;
	long long int sameWays = 0;

	for (i = 0; i<numComponents; i++)
	{
		sameWays = sameWays + (eachC[i] * (eachC[i] - 1) / 2);
	}
	cout << (totalWays - sameWays) << endl;
	return 0;
}

*/