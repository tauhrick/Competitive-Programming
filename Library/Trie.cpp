class Trie {
  const static int SZ = 26; //
  const static int B = 'a'; //
  
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
  
  int get(string& s) { //
    
  }
};
