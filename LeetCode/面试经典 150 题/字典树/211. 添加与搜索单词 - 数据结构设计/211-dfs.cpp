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

class WordDictionary {
public:
    Node *root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
    
    bool ans;
    
    void dfs(Node *curr, const string &s, int idx) {
        if (ans) { return; }
        const char &c = s[idx];
        if (idx == s.size() - 1) {
            if (c == '.') {
                for (int i = 0; i < 26; i++) {
                    if (curr->v[i] == 2) {
                        ans = true;
                        return;
                    }
                }
            } else {
                int cIdx = c - 'a';
                if (curr->v[cIdx] == 2) {
                    ans = true;
                    return;
                }
            }
        } else {
            if (c == '.') {
                for (int i = 0; i < 26; i++) {
                    if (curr->v[i]) {
                        dfs(curr->p[i], s, idx + 1);
                    }
                }
            } else {
                int cIdx = c - 'a';
                if (curr->v[cIdx]) {
                    dfs(curr->p[cIdx], s, idx + 1);
                }
            }
        }
    }
    
    bool search(string word) {
        ans = false;
        dfs(root, word, 0);
        return ans;
    }
};

int main() {
    WordDictionary wordDictionary = WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << "\n" << wordDictionary.search("pad"); // ?? False
    cout << "\n" << wordDictionary.search("bad"); // ?? True
    cout << "\n" << wordDictionary.search(".ad"); // ?? True
    cout << "\n" << wordDictionary.search("b.."); // ?? True
    return 0;
}
