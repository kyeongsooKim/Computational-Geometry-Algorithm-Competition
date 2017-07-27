/*
// Program to find Dijkstra's shortest path using set in STL

#include <iostream>
#include <list>
#include <functional> // for greater<T> and pair< , >
#include <utility> // for pair< , >

//set은 <key,value> 중 key 만 정렬시켜 저장. 한마디로 정렬된 (default : 오름차순) 배열.
//priority_queue(오름차순)대신 쓸 수 있고, vector 값을 수시로 sort() 해야할때 유용.
#include <set>
#include <vector>

using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using 
// adjacency list representation
class Graph
{
	int V;    // No. of vertices

			  // In a weighted graph, we need to store vertex 
			  // and weight pair for every edge
	list< pair<int, int> > *adj;

public:
	Graph(int V);  // Constructor

				   // function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{

	set< pair<int, int> > setds;

	vector<int> dist(V, INF);


	setds.insert(make_pair(0, src));
	dist[src] = 0;


	while (!setds.empty())
	{
		// The first vertex in Set is the minimum distance
		// vertex, extract it from set.
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = tmp.second;

		// 'i' is used to get all adjacent vertices of a vertex
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;

			//  If there is shorter path to v through u.
			if (dist[v] > dist[u] + weight)
			{
				
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				// Updating distance of v
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above fugure
	int V = 9;
	Graph g(V);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

	return 0;
}

*/