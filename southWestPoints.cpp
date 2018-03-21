#include <iostream>
#include <utility> //pair
#include <vector>
#include <algorithm> //sort
#include <ctime> //clock() , CLOCKS_PER_SEC 

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, bool> point;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define sync ios::sync_with_stdio(false); cout.precision(10); cout << fixed;
#define print_running_time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

int angle(pii a, pii b) //return the inclination of two points.
{
	return (b.se - a.se) / (b.fi - a.fi);
}

void merge(vector<point>& v, int l, int m, int r) //merging after deviding
{
	int i = l;
	point lastOfLChain;
	for (int i = l; i <= m; i++)
	{
		if (v[i].se == true)
			lastOfLChain = v[i];
	}
	
		

	for (int j = m + 1; (j <= r) && (v[j].se == true); j++)
	{
		if (lastOfLChain.fi.fi == v[j].fi.fi) // when x is same
		{
			//do nothing
		}
		else if (angle(lastOfLChain.fi, v[j].fi) > 0)
			v[j].se = false;
	}
}

void solution(vector<point>& v, int l , int r) //use divide and conquer method
{
	if (l == r)
	{
		v[l].se = true;
	}
	if (l < r)
	{
		int m = l + ((r - l) >> 1);

		solution(v, l, m);
		solution(v, m + 1, r);

		merge(v, l, m, r);
	}
}


bool myfunction(point i, point j)
{
	if (i.fi.fi == j.fi.fi)
		return (i.fi.se > j.fi.se);
	return (i.fi.fi < j.fi.fi);
}


int main() {

	sync
	vector<point> v;
	v.pb(mp(mp(3, 2), false));
	v.pb(mp(mp(1, -1), false));
	v.pb(mp(mp(2, -1), false));
	v.pb(mp(mp(5, -2), false));
	v.pb(mp(mp(0, 3), false));
	v.pb(mp(mp(2, 2), false));
	v.pb(mp(mp(-1, 4), false));

	//sorting based on x-cordinate(ascending order)
	//if x values are same, based on y-cordinate (Decending order)
	sort(v.begin(), v.end(), myfunction);  

	cout << "Given points : " << endl;
	for (vector<point>::iterator it = v.begin(); it != v.end(); ++it)
		cout << "(" << it->fi.fi << ", " << it->fi.se << ") ";
	cout << "\n\n";

	solution(v, 0, v.size() - 1); //find the southwest chain
	
	cout << "Southwest chain : " << endl;
	for (vector<point>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if (it->se == true)
			cout << "(" << it->fi.fi << ", " << it->fi.se << ") ";
	}
	cout << endl;

	print_running_time

	return 0;
}