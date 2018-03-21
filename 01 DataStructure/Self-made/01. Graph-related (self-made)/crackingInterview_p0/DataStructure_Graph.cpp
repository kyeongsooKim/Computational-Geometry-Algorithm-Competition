/*

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
#include <stdio.h>
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


stack<int> path; //for finding one line path


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

	//Depth First Search using stack
	void dfs(int startV)
	{
		stack<int> s; //using stack

		s.push(startV);
		while (!s.empty())
		{
			int now = s.top();//now : current node
			s.pop();
			if (node[now].isVisited == false)//If NOW is not passed yet
			{
				visit(node[now]);
				node[now].isVisited = true;//NOW has passed

				for (list<int>::reverse_iterator ritr = adj[now].rbegin(); ritr != adj[now].rend(); ritr++) {
					if (!node[*ritr].isVisited)
						s.push(*ritr);
				}
			}
		}
	}

	//Depth First Search using recursion
	void dfs2(int startV)
	{
		visit(node[startV]);
		node[startV].isVisited = true;

		for (list<int>::iterator itr = adj[startV].begin(); itr != adj[startV].end(); itr++)
		{
			if (!node[*itr].isVisited)
				dfs2(*itr);
		}
	}

	//breadth-first search using queue.
	void bfs(int startV)
	{
		queue<int> q;
		q.push(startV);
		node[startV].isVisited = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			visit(node[now]);

			for (list<int>::iterator itr = adj[now].begin(); itr != adj[now].end(); itr++)
			{
				if (!node[*itr].isVisited) {
					node[*itr].isVisited = true;
					q.push(*itr);
				}
			}
		}
	}

	//get disjointset.
	//queue contains representative node index of each disjoint sets 
	void getDisjointSet(int start, queue<int> * q)
	{
		for (int i = 1; i <= V; i++)
		{
			if (!node[i].isVisited)
			{
				q->push(i);
				dfs2(i);
			}
		}
	}


	//find the path which visit all vertices only once
	//works when the number of vertices is lower than 50 since time complexity is pretty high.
	//when n is 50, running-time becomes 3.7 seconds.
	bool eulerOneLine(int startV) {
		path.push(startV);
		node[startV].isVisited = true;
		bool result = false;

		for (list<int>::iterator itr = adj[startV].begin(); itr != adj[startV].end(); itr++)
		{
			
			if (!node[*itr].isVisited) {
				result = eulerOneLine(*itr);
			}
				
		}
		
		int flag = true;
		for (int i = 1; i <= V; i++) {
			if (!node[i].isVisited) {
				flag = false;
				break;
			}
		}

		if (flag == false) {
			node[startV].isVisited = false;
			path.pop();
		}
		else {
			result = true;
			return result;
		}
		
		return result;
	}
};






int main()
{
	sync





	#ifndef ONLINE_JUDGE
		cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
	return 0;
}