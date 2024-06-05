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
    
    bool search(string word) {
        queue<Node *> q;
        q.push(root);
        for (int i = 0; i < word.size() - 1; i++) {
            const char &c = word[i];
            int qSize = q.size();
            for (int j = 0; j < qSize; j++) {
                Node *curr = q.front(); q.pop();
                if (c == '.') {
                    for (int k = 0; k < 26; k++) {
                        if (curr->v[k]) {
                            q.push(curr->p[k]);
                        }
                    }
                } else {
                    int cIdx = c - 'a';
                    if (curr->v[cIdx]) {
                        q.push(curr->p[cIdx]);
                    }
                }
            }
        }
        const char &lastC = word[word.size() - 1];
        if (lastC == '.') {
            while (!q.empty()) {
                Node *curr = q.front(); q.pop();
                for (int k = 0; k < 26; k++) {
                    if (curr->v[k] == 2) { return true; }
                }
            }
            return false;
        } else {
            int lCIdx = lastC - 'a';
            while (!q.empty()) {
                Node *curr = q.front(); q.pop();
                if (curr->v[lCIdx] == 2) { return true; }
            }
            return false;
        }
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
