#include <bits/stdc++.h>
using namespace std;

const vector<int> dr = {0, 0, 1, -1};
const vector<int> dc = {1, -1, 0, 0};
const pair<int, int> NONE = {-1, -1};

void run_case() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> G(r + 1, vector<int>(c + 1));
    vector<set<int>> cols(r + 1);
    vector<set<int>> rows(c + 1);
    long long tot = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> G[i][j];
            tot += G[i][j];
            cols[i].emplace(j);
            rows[j].emplace(i);
        }
    }
    long long answer = 0;
    int steps = 0;
    vector<pair<int, int>> prev_killed;
    auto get_R = [&](int rr, int cc) {
        auto it = cols[rr].upper_bound(cc);
        if (it != cols[rr].end()) {
            return make_pair(rr, *it);
        } else {
            return NONE;
        }
    };
    auto get_D = [&](int rr, int cc) {
        auto it = rows[cc].upper_bound(rr);
        if (it != rows[cc].end()) {
            return make_pair(*it, cc);
        } else {
            return NONE;
        }
    };
    auto get_L = [&](int rr, int cc) {
        auto it = cols[rr].lower_bound(cc);
        if (it != cols[rr].begin()) {
            --it;
            return make_pair(rr, *it);
        } else {
            return NONE;
        }
    };
    auto get_U = [&](int rr, int cc) {
        auto it = rows[cc].lower_bound(rr);
        if (it != rows[cc].begin()) {
            --it;
            return make_pair(*it, cc);
        } else {
            return NONE;
        }
    };
    while (true) {
        ++steps;
        answer += tot;
        if (steps == 1) {
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    int cnt = 0;
                    int sum = 0;
                    for (int dir = 0; dir < 4; ++dir) {
                        int _i = i + dr[dir];
                        int _j = j + dc[dir];
                        if (1 <= _i && _i <= r && 1 <= _j && _j <= c) {
                            ++cnt;
                            sum += G[_i][_j];
                        }
                    }
                    if (cnt * G[i][j] < sum) {
                        prev_killed.emplace_back(i, j);
                    }
                }
            }
        } else {
            set<pair<int, int>> killed;
            auto check = [&](pair<int, int> pp) {
                if (pp == NONE) {
                    return;
                }
                int rr = pp.first;
                int cc = pp.second;
                int cnt = 0;
                int sum = 0;
                auto add = [&](pair<int, int> foo) {
                    if (foo == NONE) {
                        return;
                    }
                    ++cnt;
                    sum += G[foo.first][foo.second];
                };
                add(get_L(rr, cc));
                add(get_R(rr, cc));
                add(get_U(rr, cc));
                add(get_D(rr, cc));
                if (cnt * G[rr][cc] < sum) {
                    killed.emplace(rr, cc);
                }
            };
            for (auto &pp : prev_killed) {
                int rr = pp.first;
                int cc = pp.second;
                check(get_L(rr, cc));
                check(get_R(rr, cc));
                check(get_U(rr, cc));
                check(get_D(rr, cc));
            }
            prev_killed.clear();
            for (auto &pp : killed) {
                prev_killed.emplace_back(pp);
            }
        }
        if (prev_killed.empty()) {
            break;
        }
        for (auto &pp : prev_killed) {
            tot -= G[pp.first][pp.second];
            rows[pp.second].erase(pp.first);
            cols[pp.first].erase(pp.second);
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        run_case();
    }
    return 0;
}

