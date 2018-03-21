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
#include <cstdlib> //rand, srand
#include <cstring>
#include <stdio.h>

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

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

vector<vector<bool>> visited(100005, vector<bool>(100005, false));
vector<int> setCount(100005);
int idx = 0;

void areaCheck2(int m, int n, vector<vector<int>> picture, int a, int b) {

	visited[a][b] = true;
	setCount[idx]++;
	if (b > 0)
		if ((picture[a][b - 1] == picture[a][b]) && visited[a][b - 1] == false)
			areaCheck2(m, n, picture, a, b - 1);
	if (b < n - 1)
		if ((picture[a][b + 1] == picture[a][b]) && visited[a][b + 1] == false)
			areaCheck2(m, n, picture, a, b + 1);
	if (a > 0)
		if ((picture[a - 1][b] == picture[a][b]) && visited[a - 1][b] == false)
			areaCheck2(m, n, picture, a - 1, b);
	if (a < m - 1)
		if ((picture[a + 1][b] == picture[a][b]) && visited[a + 1][b] == false)
			areaCheck2(m, n, picture, a + 1, b);

}

void areaCheck(int m, int n, vector<vector<int>> picture, int a, int b) {

	areaCheck2(m, n, picture, a, b);
	idx++;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	rep(i, m) {
		rep(j, n) {
			if (visited[i][j] == false && picture[i][j] != 0)
				areaCheck(m, n, picture, i, j);
		}
	}

	number_of_area = idx;
	rep(i, setCount.size() - 1) {
		if (setCount[i] >= max_size_of_one_area)
			max_size_of_one_area = setCount[i];
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {


	sync

	vector<vector<int>> v(6, vector<int>(4));
	v[0][0] = 1; v[0][1] = 1; v[0][2] = 1; v[0][3] = 0;
	v[1][0] = 1; v[1][1] = 2; v[1][2] = 2; v[1][3] = 0;
	v[2][0] = 1; v[2][1] = 0; v[2][2] = 0; v[2][3] = 1;
	v[3][0] = 0; v[3][1] = 0; v[3][2] = 0; v[3][3] = 1;
	v[4][0] = 0; v[4][1] = 0; v[4][2] = 0; v[4][3] = 3;
	v[5][0] = 0; v[5][1] = 0; v[5][2] = 0; v[5][3] = 3;

	vector<int> ans;
	ans = solution(6, 4, v);
	cout << ans[0] << endl;
	cout << ans[1] << endl;

	print_running_time
}