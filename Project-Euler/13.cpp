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
const int INF = INT_MAX, MOD = 1e9 + 7, N = 100 + 10, M = N / 2;

int num[N][M], carry[M + 1], sum[M + 1];

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
	for (int cnt = 1; cnt <= 100; ++cnt) {
		for (int i = 50; i >= 1; --i) {
			char ch;
			cin >> ch;
			num[cnt][i] = ch - '0';
		}
	}
	for (int dig = 1; dig < M; ++dig) {
		int tot = carry[dig];
		for (int r = 1; r < N; ++r) {
			tot += num[r][dig];
		}
		sum[dig] = tot % 10;
		carry[dig + 1] = tot / 10;
	}
	assert(carry[M] == 0);
	for (int dig = M; dig >= 0; --dig) {
		if (sum[dig] != 0) {
			for (int i = dig, rem = 10; rem != 0; --rem, --i) {
				cout << sum[i];
			}
			cout << "\n";
			return;
		}
	}
	assert(false);
}