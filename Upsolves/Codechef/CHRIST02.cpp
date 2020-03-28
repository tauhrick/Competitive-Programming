#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, LG = log2(N) + 2;

struct Chain {
    int head, sz;

    Chain() {
        head = sz = 0;
    }
};

struct Node {
    int chain_no, chain_pos, sub_sz, par, tot_pos, dep;

    Node() {
        chain_no = chain_pos = sub_sz = par = tot_pos = dep = 0;
    }
};

int curr_chain, ctr;
vector<Chain> chain_info(N);
vector<Node> node_info(N);
vector<int> order;
int n, q;
vector<int> val(N);
vector<vector<int>> G(N);
vector<vector<int>> up(N, vector<int>(LG));
vector<vector<int>> sg_tree(4 * N + 4);

void pre_sz(int u, int p, int d) {
    node_info[u].sub_sz = 1;
    node_info[u].par = p;
    node_info[u].dep = d;
    up[u][0] = p;
    for (int i = 1; i < LG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto v : G[u]) {
        if (v != p) {
            pre_sz(v, u, d + 1);
            node_info[u].sub_sz += node_info[v].sub_sz;
        }
    }
}

void add_to_chain(int u) {
    if (chain_info[curr_chain].sz == 0) {
        chain_info[curr_chain].head = u;
    }
    ++chain_info[curr_chain].sz;
    node_info[u].chain_no = curr_chain;
    node_info[u].chain_pos = chain_info[curr_chain].sz;
    order.emplace_back(u);
    node_info[u].tot_pos = ++ctr;
}

void decompose(int u, int p) {
    add_to_chain(u);
    int max_sz = -1, special_node = -1;
    for (auto v : G[u]) {
        if (v != p) {
            if (node_info[v].sub_sz > max_sz) {
                max_sz = node_info[v].sub_sz;
                special_node = v;
            }
        }
    }
    if (special_node != -1) {
        decompose(special_node, u);
    }
    for (auto v : G[u]) {
        if (v != p && v != special_node) {
            ++curr_chain;
            decompose(v, u);
        }
    }
}

void hld(int root) {
    curr_chain = 1;
    ctr = 0;
    order.emplace_back(0);
    pre_sz(root, 0, 0);
    decompose(root, 0);
    assert(ctr == n);
}

int get_lca(int u, int v) {
    int du = node_info[u].dep;
    int dv = node_info[v].dep;
    if (du < dv) {
        swap(u, v);
        swap(du, dv);
    }
    int diff = du - dv;
    for (int i = 0; i < LG; ++i) {
        if (diff & (1 << i)) {
            u = up[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void build(int tv, int tl, int tr, vector<int> &x) {
    if (tl == tr) {
        sg_tree[tv].emplace_back(x[tl]);
    } else {
        int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
        build(lc, tl, tm, x);
        build(rc, tm + 1, tr, x);
        merge(sg_tree[lc].begin(), sg_tree[lc].end(), sg_tree[rc].begin(), sg_tree[rc].end(), back_inserter(sg_tree[tv]));
    }
}

int get(int ql, int qr, int ll, int rr, int tv = 1, int tl = 1, int tr = n) {
    if (qr < tl || tr < ql) {
        return 0;
    } else if (ql <= tl && tr <= qr) {
        int l = lower_bound(sg_tree[tv].begin(), sg_tree[tv].end(), ll) - sg_tree[tv].begin();
        int r = upper_bound(sg_tree[tv].begin(), sg_tree[tv].end(), rr) - sg_tree[tv].begin();
        --r;
        return max(0, r - l + 1);
    } else {
        int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
        return get(ql, qr, ll, rr, lc, tl, tm) + get(ql, qr, ll, rr, rc, tm + 1, tr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    hld(1);
    vector<int> cols(n + 1);
    for (int i = 1; i <= n; ++i) {
        cols[i] = val[order[i]];
    }
    build(1, 1, n, cols);
    int last = 0;
    while (q--) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        int u = (a ^ last) % n + 1;
        int v = (b ^ last) % n + 1;
        int lca_node = get_lca(u, v);
        auto solve = [&](int node) {
            int ans = 0;
            while (node != 0) {
                int pos = node_info[node].chain_pos;
                int order_pos = node_info[node].tot_pos;
                ans += get(order_pos - pos + 1, order_pos, l, r);
                assert(order[order_pos - pos + 1] == chain_info[node_info[node].chain_no].head);
                node = up[order[order_pos - pos + 1]][0];
            }
            return ans;
        };
        last = solve(u) + solve(v) - 2 * solve(lca_node);
        if (l <= val[lca_node] && val[lca_node] <= r) {
            ++last;
        }
        cout << last << "\n";
    }
    return 0;
}

