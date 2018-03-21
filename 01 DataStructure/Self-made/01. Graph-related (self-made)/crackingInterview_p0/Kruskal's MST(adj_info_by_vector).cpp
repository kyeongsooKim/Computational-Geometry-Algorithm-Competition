/*

#include <utility> //for pair
#include <vector>
#include <algorithm> //for sort()
#include <iostream>


using namespace std;

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

	// Are objects x and y in the same set?
	bool connected(int x, int y)    {
        return find(x) == find(y);
    }

};

typedef  pair<int, int> iPair; // Creating shortcut for an integer pair

typedef struct weighted_graph
{
	int V; //vertex
	int E; //edges
	vector< pair<int, iPair> > edges; //adjacent information of edges.

	weighted_graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	void addEdge(int u, int v, int w)
	{
		edges.push_back({ w,{ u, v } });
	}


	// Functions returns weight of the MST using Kruskal's MST algorithm
	int kruskalMST()
	{
		int mst_weight = 0; // Initialize result

		// Sort edges in increasing order on basis of cost
		sort(edges.begin(), edges.end());

		// Create disjoint sets
		disjointSets ds(V);

		// Iterate through all sorted edges
		vector< pair<int, iPair> >::iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			int u = it->second.first;
			int v = it->second.second;

			int set_u = ds.find(u);
			int set_v = ds.find(v);

			// Check if the selected edge is creating
			// a cycle or not (Cycle is created if u and v belong to same set)
			if (set_u != set_v)
			{
				// Current edge will be in the MST so print it
				cout << u << " - " << v << endl;

				// Update MST weight
				mst_weight += it->first;

				// Merge two sets
				ds.merge(set_u, set_v);
			}
		}

		return mst_weight;
	}
} graph;








// Driver program to test above functions
int main()
{
	//Let us create above shown weighted and unidrected graph
	int V = 9, E = 14;
	graph g(V, E);

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

	cout << "Edges of MST are \n";
	int mst_weight = g.kruskalMST();

	cout << "\nWeight of MST is " << mst_weight << endl;

	return 0;
}



*/