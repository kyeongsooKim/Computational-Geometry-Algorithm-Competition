/*

#include <utility> //for pair
#include <list>
#include <queue>
#include <vector>
#include <functional> //for greater<>
#include <iostream>

using namespace std;
#define INF 0x3f3f3f3f
 
typedef pair<int, int> iPair; // Creating shortcut for an integer pair
 
//weighted graph using adjacency list representation
class graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex and weight pair for every edge
    list< iPair > *adj;
 
public:
	// Allocates memory for adjacency list
	graph(int V)
	{
		this->V = V;
		adj = new list<iPair>[V];
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// Prints shortest paths from src to all other vertices
	int primMST(int source)
	{
		int src = source;
		int mst_weight = 0; // Initialize result
		priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

		// Create a vector for dists and initialize all dists as infinite (INF)
		vector<int> dist(V, INF);
		vector<int> parent(V, -1); // To store parent array which in turn store MST
		vector<bool> isInMST(V, false); // To keep track of vertices included in MST

		// Insert source itself in priority queue and initialize its dist as 0.
		pq.push(make_pair(0, src));
		dist[src] = 0;

		// Looping till priority queue becomes empty
		while (!pq.empty())
		{
			
			int u = pq.top().second;
			if (isInMST[u] != true)
				mst_weight += pq.top().first;

			pq.pop();
			isInMST[u] = true;  // Include vertex in MST

			// 'i' is used to get all adjacent vertices of a vertex
			list< pair<int, int> >::iterator i;
			for (i = adj[u].begin(); i != adj[u].end(); ++i)
			{
				// Get vertex label and weight of current adjacent
				// of u.
				int v = (*i).first;
				int weight = (*i).second;

				//  If v is not in MST and weight of (u,v) is smaller
				// than current dist of v
				if (isInMST[v] == false && dist[v] > weight)
				{
					// Updating dist of v
					dist[v] = weight;
					pq.push(make_pair(dist[v], v));
					parent[v] = u;
				}
			}
		}

		// Print edges of MST using parent array
		for (int i = 1; i < V; ++i)
			cout << parent[i] << " - " << i << endl;

		return mst_weight;
	}
};
 

 
int main()
{
    // create the graph given in above fugure
    int V = 9;
    graph g(V);
 
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
 
   

	int mst_weight = g.primMST(0); //argument : starting vertex(root of MST)

	cout << "\nWeight of MST is " << mst_weight << endl;
 
    return 0;
}

*/