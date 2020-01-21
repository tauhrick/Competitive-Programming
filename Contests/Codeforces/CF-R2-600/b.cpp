#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    map<int, int> match;
    set<int> rem;
    vector<int> days;
    for (int i = 0; i < n; ++i) {
        if (v[i] > 0) {
            if (match.count(v[i])) {
                cout << "-1\n";
                return;
            } else {
                match[v[i]] = 1;
                rem.insert(v[i]);
            }
        } else {
            if (match[-v[i]] != 1) {
                cout << "-1\n";
                return;
            } else {
                match[-v[i]] = 2;
                rem.erase(-v[i]);
                if (rem.empty()) {
                    days.emplace_back(i);
                    match.clear();
                }
            }
        }  
    }
    if (!rem.empty()) {
        cout << "-1";
    } else {
        cout << days.size() << "\n";
        int prv = -1;
        for (int i = 0; i < (int) days.size(); ++i) {
            cout << days[i] - prv << " ";
            prv = days[i];
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
