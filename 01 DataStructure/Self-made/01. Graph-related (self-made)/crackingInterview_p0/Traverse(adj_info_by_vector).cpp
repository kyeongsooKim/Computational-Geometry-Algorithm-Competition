/*
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Node {
	bool isVisited;
	int value;
};

//undirected graph
struct Ugraph {
	vector<Node> node;
	vector< vector<bool> > adj;
	int numOfNodes;
	int numOfEdges;

public:
	Ugraph(int N, int M) {
		vector<Node> temp(N + 1); // make node index and vector index same for convienece
		node = temp;
		for (int i = 1; i < temp.size(); i++) {
			node[i].value = i;
		}
		vector< vector<bool> > temp2(M + 1, vector<bool>(M + 1));
		adj = temp2;
		numOfNodes = N;
		numOfEdges = M;
	};

	void resetVisited() {
		for (int i = 1; i <= numOfNodes; i++)
			node[i].isVisited = false;
	};
};

void visit(Node node) {
	cout << node.value << " ";
}

//Depth First Search using stack
void dfs(Ugraph g, int startNum)
{
	stack<int> s; //using stack

	int N = g.numOfNodes; //N : Number of vertex
	int M = g.numOfEdges;	//M : Number of edge
	int V = startNum; //V : Start vertex number

	s.push(V);
	while (!s.empty())
	{
		int now = s.top();//now : current node
		s.pop();
		if (g.node[now].isVisited == false)//If NOW is not passed yet
		{
			visit(g.node[now]);
			g.node[now].isVisited = true;//NOW has passed

			for (int i = N; i > 0; i--) {
				if (g.node[i].isVisited == false && g.adj[now][i] == true) {
					s.push(i);
				}
			}
		}
	}
}

//Depth First Search using recursion
void dfs2(Node * root, Ugraph * g)
{
	visit(*root);
	root->isVisited = true;

	for (int i = 1; i <= g->numOfNodes; i++) {
		if (g->adj[root->value][i] == true) {
			if (g->node[i].isVisited == false)
				dfs2(&g->node[i], g);
		}
	}
}

void bfs(Ugraph g, int v)
{
	queue<int> q;
	q.push(v);
	g.node[v].isVisited = true;

	while (!q.empty()) {
		int r = q.front();
		q.pop();
		visit(g.node[r]);

		for (int i = 1; i <= g.numOfNodes; i++) {
			if (g.adj[r][i] == true && g.node[i].isVisited == false) {
				g.node[i].isVisited = true;
				q.push(i);
			}
		}
	}


}


int main()
{
	ifstream fin("input.txt");
	string str;
	getline(fin, str);
	char * context; // for strtok_s

	int N = atoi(strtok_s((char*)str.c_str(), " ", &context));  //N : Number of vertex
	int M = atoi(strtok_s(NULL, " ", &context));  //M : Number of edge
	int V = atoi(strtok_s(NULL, " ", &context));  //V : Start vertex number
	Ugraph graph(N, M); //create graph

						//Edge connection
	for (int i = 0; i < M; i++)
	{
		getline(fin, str);
		int a = atoi(strtok_s((char*)str.c_str(), " ", &context));
		int b = atoi(strtok_s(NULL, " ", &context));
		graph.adj[a][b] = true;
		graph.adj[b][a] = true;

	}

	dfs(graph, V); //Depth First Search using stack
	cout << endl;

	dfs2(&graph.node[V], &graph); //Depth First Search using recursion
	cout << endl;

	graph.resetVisited();

	bfs(graph, V); //Breadth-First Search using recursion
	cout << endl;


	return 0;
}

*/