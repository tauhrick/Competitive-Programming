const int N = 1e5 + 10;

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

void pre_sz(int u, int p, int d) {
    node_info[u].sub_sz = 1;
    node_info[u].par = p;
    node_info[u].dep = d;
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
