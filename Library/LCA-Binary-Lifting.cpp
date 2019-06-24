int timer, l;
vector < int > tin, tout;
vector < vector < int > > up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    } else if (isAncestor(v, u)) {
        return v;
    }
    for (int i = l; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void preProcess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector < int >(l + 1));
    dfs(root, root);
}