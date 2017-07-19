#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Node {
	bool isVisited;
	//int value;
};

//undirected graph
struct Ugraph {
	vector<Node> node;
	vector< vector<bool> > adj;
	int numOfNodes;
	int numOfEdges;
	
	public: Ugraph(int N, int M) {
		vector<Node> temp(N+1); // make node index and vector index same for convienece
		node = temp;
		vector< vector<bool> > temp2(M+1, vector<bool>(M+1));
		adj = temp2;
		numOfNodes = N;
		numOfEdges = M;
	}
};

void visit(int now) {
	cout << now << " ";
}

//Depth First Search using stack
void dfs(Ugraph g, int startNum)
{
	stack<int> s; //using stack

	int N = g.numOfNodes; //N : Number of vertex
	int M = g.numOfEdges;	//M : Number of edge
	int V = startNum; //V : Start vertex number

	//initialization of Node information.
	fill(g.node[1].isVisited, g.node[N].isVisited,false); //node[0] = dummy node;
	for (int i =1; i <= M ;i++)
		fill(g.adj[i][1], g.adj[i][M], false);
	

	s.push(V);
	while (!s.empty())
	{
		int now = s.top();//now : current node
		s.pop();
		if (g.node[now].isVisited == false)//If NOW is not passed yet
		{
			g.node[now].isVisited = true;//NOW has passed
			visit(now); 
			
			for (int i = N; i > 0; i--) {
				if (g.node[now].isVisited == true && g.adj[now][i] == true) {
					s.push(i);
				}
			}
		}
	}
}

//Depth First Search using recursion
void dfs2(Ugraph g, int startNum)
{
	int N = g.numOfNodes; //N : Number of vertex
	int M = g.numOfEdges;	//M : Number of edge
	int V = startNum; //V : Start vertex number

	fill(&g.node[0].isVisited, &g.node[N].isVisited, false); //initialization of nodes.

	
}

void bfs(Ugraph g, int startNum)
{
	int N = g.numOfNodes; //N : Number of vertex
	int M = g.numOfEdges;	//M : Number of edge
	int V = startNum; //V : Start vertex number

	fill(&g.node[0].isVisited, &g.node[N].isVisited, false); //initialization of nodes.


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

	dfs(graph, V); //Depth First Search

	return 0;
}