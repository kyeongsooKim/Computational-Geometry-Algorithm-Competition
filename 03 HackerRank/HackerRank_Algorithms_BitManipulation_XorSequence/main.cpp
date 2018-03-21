#include <fstream> //for fout, fin
#include <iostream> //for cout, cin

#include <list>
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
#define rep(i, a) for (int i = 0; i < (a); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a) for (int i = (a) - 1; i >= 0; i--)
#define rrep2(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sync ios::sync_with_stdio(false); cin.tie(nullptr); cout.precision(10);

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int MOD = (int)1000000007;
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

ll a(ll n) { //a(n) = 1^2^...^n
	ll rem = n % 4;
	if (rem == 0) return n;
	if (rem == 1) return 1;
	if (rem == 2) return n + 1;
	if (rem == 3) return 0;
	return 0;
}

ll g(ll n) //g(n) = a(1)^a(2)^...^a(n)
{
	ll rem = n % 8;
	if (rem == 0) return n;
	if (rem == 1) return n;
	if (rem == 2) return 2;
	if (rem == 3) return 2;
	if (rem == 4) return n + 2;
	if (rem == 5) return n + 2;
	if (rem == 6) return 0;
	if (rem == 7) return 0;
	return 0;
}

int main() {

	sync
	cout << fixed;
	#ifdef LOCAL_DEFINE
		freopen("input.txt", "rt", stdin);
	#endif

	int testNum;
	cin >> testNum;
	while (testNum--) {

		ll l, r, ans;
		cin >> l >> r;
		ans = g(r) ^ g(l - 1);
		cout << ans << endl;
	}

	#ifdef LOCAL_DEFINE
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
	return 0;
}
