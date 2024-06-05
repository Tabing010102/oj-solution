#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v[26];
    Node *p[26];
    Node() {
        for (int i = 0; i < 26; i++) {
            v[i] = 0;
            p[0] = nullptr;
        }
    }
};

class Trie {
public:
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++) {
            const char &c = word[i];
            int cIdx = c - 'a';
            if (!curr->v[cIdx]) {
                Node *nN = new Node();
                curr->v[cIdx] = (i == word.size() - 1) ? 2 : 1;
                curr->p[cIdx] = nN;
                curr = nN;
            } else {
                if (i == word.size() - 1) { curr->v[cIdx] = 2; }
                curr = curr->p[cIdx];
            }
        }
    }
    
    bool search(string word) {
        Node *curr = root;
        for (int i = 0; i < word.size() - 1; i++) {
            const char &c = word[i];
            int cIdx = c - 'a';
            if (!curr->v[cIdx]) {
                return false;
            } else {
                curr = curr->p[cIdx];
            }
        }
        return curr->v[word[word.size() - 1] - 'a'] > 0;
    }
};

const int MAXN = 12 + 3;
const int DELTA[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
const bool DEBUG = false;

class Solution {
public:
//    unordered_set<string> us;
    int m, n;
    bool vis[MAXN][MAXN];
    void dfs(vector<vector<char>>& G, int x, int y, string &s, Trie &trie) {
        vis[x][y] = true;
        s.push_back(G[x][y]);
        bool ce = false;
        for (int i = 0; i < 4 && s.size() < 10; i++) {
            int tx = x + DELTA[i][0], ty = y + DELTA[i][1];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n) { continue; }
            if (vis[tx][ty]) { continue; }
            ce = true;
            dfs(G, tx, ty, s, trie);
        }
        if (s.size() == 10 || !ce) {
            if (DEBUG) { cout << "add " << s << endl; }
//            us.insert(s);
            trie.insert(s);
        }
        vis[x][y] = false;
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<char>>& G = board;
        Trie trie = Trie();
//        us.clear();
        memset(vis, 0, sizeof(vis));
        m = G.size();
        n = G[0].size();
        string s = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(G, i, j, s, trie);
            }
        }
        vector<string> ans;
        for (string word : words) {
            if (trie.search(word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> x = {
        vector<char>{'o', 'a', 'a', 'n'},
        vector<char>{'e', 't', 'a', 'e'},
        vector<char>{'i', 'h', 'k', 'r'},
        vector<char>{'i', 'f', 'l', 'v'},
    };
    vector<string> y = {"oath","pea","eat","rain"};
    Solution s;
    auto ans = s.findWords(x, y);
    for (auto a : ans) { cout << a << endl; }
    return 0;
}
