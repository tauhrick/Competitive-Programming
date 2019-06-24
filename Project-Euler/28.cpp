/* 
chirag11032000
Chirag Thakur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template < typename T > using OrderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 1200 + 10, S = 1000;

struct ind {
	int r, c;

	ind(int i, int j) {
		r = i + 600;
		c = j + 600;
	}
};

int grid[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ctr = 1;

void test_case();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}

void test_case() {
	memset(grid, -1, sizeof grid);
	grid[600][600] = 1;
	int i = 0, j = 0, rem = S, num = 1;
	while (rem != 0) {
		for (int dr = 0; dr < 4; ++dr) {
			if (dr == 2) {
				++ctr;
			}
			for (int times = 0; times < ctr; ++times) {
				j += dx[dr];
				i += dy[dr];
				ind pos(i, j);
				grid[pos.r][pos.c] = ++num;
			}
		}
		++ctr;
		rem -= 2;
	}
	while (ctr--) {
		++j;
		ind pos(i, j);
		grid[pos.r][pos.c] = ++num;
	}
	auto get = [](int x, int y, int rem) {
		int sum = 0, i = 0, j = 0;
		while (rem--) {
			j += x;
			i += y;
			ind pos(i, j);
			sum += grid[pos.r][pos.c];
		}
		return sum;
	};
	int ans = 1 + get(-1, 1, S / 2) + get(-1, -1, S / 2) + get(1, 1, S / 2) + get(1, -1, S / 2);
	cout << ans << "\n";
}