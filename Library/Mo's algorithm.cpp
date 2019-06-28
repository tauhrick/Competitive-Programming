int BLOCK_SZ;
vector<int> query_ans;

struct Query {
	int l, r, idx;

	bool operator <(Query& o) const {
		return make_pair(l / BLOCK_SZ, r) < make_pair(o.l / BLOCK_SZ, o.r);
	}
};


void mo_s_algo(vector<Query>& queries) {
	sort(all(queries));
	int curr_l = -1, curr_r = -1;
	for (auto& q: queries) {
		while (curr_l > q.l) {
			add(--curr_l);
		}
		while (curr_r < q.r) {
			add(++curr_r);
		}
		while (curr_l < q.l) {
			remove(curr_l++);
		}
		while (curr_r > q.r) {
			remove(curr_r--);
		}
		query_ans[q.idx] = solve_query(q);
	}
}

void add(int pos) {

}

void remove(int pos) {
	
}

int solve_query(Query& q) {
	
}