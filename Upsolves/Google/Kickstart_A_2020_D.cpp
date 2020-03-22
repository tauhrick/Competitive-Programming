#include <bits/stdc++.h>
using namespace std;

class Trie {
    const static int SZ = 26; //
    const static int B = 'A'; //
  
public:
    struct Node {
        Node* nxt[SZ];
        int cnt_pass;
        int cnt_last;

        Node(int _cnt_pass = 0, int _cnt_last = 0) {
            cnt_pass = _cnt_pass;
            cnt_last = _cnt_last;
            for (int i = 0; i < SZ; ++i) {
                nxt[i] = nullptr;
            }
        }
    };

    Node* head = new Node();

    void insert(string& s) {
        Node* node = head;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto& curr = *node;
            int e = s[i] - B;
            if (curr.nxt[e] == nullptr) {
                curr.nxt[e] = new Node();
            }
            node = curr.nxt[e];
            ++(*node).cnt_pass;
        }
        ++(*node).cnt_last;
    }

    void erase(string& s) {
        Node* node = head;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto& curr = *node;
            int e = s[i] - B;
            assert(curr.nxt[e] != nullptr);
            if (((curr.nxt[e]) -> cnt_pass) == 1) {
                curr.nxt[e] = nullptr;
                return;
            }
            node = curr.nxt[e];
            --(*node).cnt_pass;
        }
        --(*node).cnt_last;
    }

    int get(int k, Node *u, int dep) { //
        int ans = 0;
        for (int i = 0; i < SZ; ++i) {
            if (u->nxt[i]) {
                ans += get(k, u->nxt[i], dep + 1);
            }
        }
        ans += (u->cnt_pass) / k;
        return ans;
    }

    int get(int k) {
        return get(k, head, 0);
    }
};

void test() {
    int n, k;
    cin >> n >> k;
    Trie t;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        t.insert(s);
    }
    cout << t.get(k) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test();
    }
    return 0;
}

