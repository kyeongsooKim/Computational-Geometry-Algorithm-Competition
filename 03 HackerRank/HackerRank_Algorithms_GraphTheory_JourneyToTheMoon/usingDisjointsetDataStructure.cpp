


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

	disjointSets s(n);

	for (i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		s.addEdge(u, v);
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