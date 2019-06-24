struct Scc {
    int V, groupCnt;
    vector < vector < int > > adj, radj;
    vector < int > groupNum, vis;
    stack < int > stk;

    // V = number of vertices
    Scc(int V): V(V), groupCnt(0), groupNum(V), vis(V), adj(V), radj(V) {}

    // Call this to add an edge (0-based)
    void addEdge(int v1, int v2) {
        adj[v1].eb(v2);
        radj[v2].eb(v1);
    }

    void fillForward(int x) {
        vis[x] = true;
        for (int i = 0; i < adj[x].size(); i++) {
            if (!vis[adj[x][i]]) {
                fillForward(adj[x][i]);
            }
        }
        stk.push(x);
    }

    void fillBackward(int x) {
        vis[x] = false;
        groupNum[x] = groupCnt;
        for (int i = 0; i < radj[x].size(); i++) {
            if (vis[radj[x][i]]) {
                fillBackward(radj[x][i]);
            }
        }
    }

    // Returns number of strongly connected components.
    // After this is called, groupNum contains component assignments (0-based)
    int getScc() {
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                fillForward(i);
            }
        }
        groupCnt = 0;
        while (!stk.empty()) {
            if (vis[stk.top()]) {
                fillBackward(stk.top());
                groupCnt++;
            }
            stk.pop();
        }
        return groupCnt;
    }
};