ll dis[N], par[N];
bool seen[N];

void dijkstra(ll src) {
	MinPriorityQueue < pll > pq;
	fill(dis + 1, dis + 1 + v, INF);
	pq.push({0, src});
	par[src] = -1;
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if (seen[x.second]) {
			continue;
		}
		seen[x.second] = true;
		for (auto &y : g[x.second]) {
			ll i = y.first;
			ll d = x.first + y.second;
			if (!seen[i] && d < dis[i]) {
				dis[i] = d;
				pq.push({dis[i], i});
				par[i] = x.second;
			}
		}
	}
}