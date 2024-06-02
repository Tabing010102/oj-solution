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
        return curr->v[word[word.size() - 1] - 'a'] == 2;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            const char &c = prefix[i];
            int cIdx = c - 'a';
            if (!curr->v[cIdx]) {
                return false;
            } else {
                curr = curr->p[cIdx];
            }
        }
        return curr;
    }
};

int main() {
    Trie trie = Trie();
    trie.insert("apple");
    cout << "\n" << trie.search("apple");   // ?? True
    cout << "\n" << trie.search("app");     // ?? False
    cout << "\n" << trie.startsWith("app"); // ?? True
    trie.insert("app");
    cout << "\n" << trie.search("app");     // ?? True
    return 0;
}
