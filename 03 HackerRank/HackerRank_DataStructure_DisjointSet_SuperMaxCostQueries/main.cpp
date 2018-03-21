#include <bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<int, pii>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int mod = 1e9 + 7;

int ADD(int a, int b, int m = mod) {
	int s = a;
	s += b;
	if (s >= m)
		s -= m;
	return s;
}

int MUL(int a, int b, int m = mod) {
	return (1LL * a * b % m);
}

int power(int a, int b, int m = mod) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = 1LL * res * a % m;
		}
		a = 1LL * a * a % m;
		b /= 2;
	}
	return res;
}

ll nC2(ll x) {
	return (x * (x - 1) / 2);
}

const int maxn = 1e5 + 5;

int n, q;
piii A[maxn];


class Disjoint_Set {
public:
	int n, max_component;
	ll ans;
	vector<int> P, R, S;
	Disjoint_Set(int n) {
		this->n = n;
		P.resize(n + 1);
		R.resize(n + 1);
		S.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			R[i] = 0;
			P[i] = i;
			S[i] = 1;
		}
		ans = 0;
	}

	int find(int x) {
		if (x != P[x]) {
			P[x] = find(P[x]);
		}
		return P[x];
	}

	bool add_edge(int x, int y) {
		int rx, ry;
		rx = find(x);
		ry = find(y);
		if (rx != ry) {
			if (R[rx] < R[ry]) {
				P[rx] = ry;
				ans -= nC2(S[rx]);
				ans -= nC2(S[ry]);
				S[ry] += S[rx];
				ans += nC2(S[ry]);
			}
			else {
				P[ry] = rx;
				ans -= nC2(S[rx]);
				ans -= nC2(S[ry]);
				S[rx] += S[ry];
				ans += nC2(S[rx]);
			}
			if (R[rx] == R[ry]) {
				R[rx] ++;
			}
			return true;
		}
		return false;
	}

};

void solve() {
	cin >> n >> q;
	assert(n <= 100000 && n >= 2);
	assert(q <= 100000 && q >= 1);
	int i;
	fr(i, 1, n - 1) {
		int u, v, c;
		cin >> u >> v >> c;
		assert(u <= n && u >= 1);
		assert(v <= n && v >= 1);
		assert(c <= 1000000000 && c >= 1);
		A[i] = { c,{ u, v } };
	}

	sort(A + 1, A + n);

	Disjoint_Set dsu(n);
	ll prev = 0;

	vl s;
	vi v;

	i = 1;
	while (i < n) {
		int c = A[i].ft;
		while (i < n && c == A[i].ft) {
			if (!dsu.add_edge(A[i].sd.ft, A[i].sd.sd)) {
				assert(0);
			}
			i++;
		}
		v.pb(c);
		s.pb(dsu.ans - prev);
		prev = dsu.ans;
	}

	ll sum = 0;
	for (auto &it : s) {
		sum += it;
		it = sum;
	}


	while (q--) {
		int l, r;
		cin >> l >> r;
		assert(l <= r);
		if (r < v[0]) {
			cout << 0 << "\n";
		}
		else {
			r = upper_bound(all(v), r) - v.begin();
			r--;
			if (l <= v[0]) {
				cout << s[r] << "\n";
			}
			else {
				l = lower_bound(all(v), l) - v.begin();
				l--; assert(l <= r);
				cout << (s[r] - s[l]) << "\n";
			}
		}
	}
}

int main() {
	solve();
	return 0;
}