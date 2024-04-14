#include <bits/stdc++.h>

using namespace std;

struct Node {
    int k;
    Node *priv, *next;
    Node(int a) : k(a), priv(nullptr), next(nullptr) {}
};

void printc(Node *c) {
    printf("Nodes: ");
    while (c != nullptr) {
        printf("%d ", c->k);
        c = c->next;
    }
    printf("\n");
}

class LRUCache {
public:
    int n, c;
    unordered_map<int, int> md;
    unordered_map<int, Node *> mn;
    Node *vhead, *vtail;
    LRUCache(int capacity) {
        n = capacity;
        c = 0;
        md.clear();
        mn.clear();
        vhead = new Node(-999);
        vtail = new Node(999);
        vhead->next = vtail;
        vtail->priv = vhead;
    }
    
    ~LRUCache() {
        delete vhead;
        delete vtail;
    }
    
    int get(int key) {
        printf("get(%d)\n", key);
        if (md.find(key) != md.end()) {
            moveToHead(mn[key]);
            printc(vhead);
            return md[key];
        }
        else { return -1; }
    }
    
    void put(int key, int value) {
        printf("put(%d, %d)\n", key, value);
        if (md.find(key) != md.end()) {
            md[key] = value;
            Node *cnt = mn[key];
            if (cnt != vhead->next) {
                if (cnt == vtail->priv) {
                    vtail->priv = cnt->priv;
                    cnt->priv->next = vtail;
                }
                moveToHead(cnt);
            }
        } else {
            if (c < n) {
                c++;
                md[key] = value;
                mn[key] = new Node(key);
                moveToHead(mn[key]);
            } else {
                removeTail();
                md[key] = value;
                mn[key] = new Node(key);
                moveToHead(mn[key]);
            }
        }
        printc(vhead);
    }
    
    void moveToHead(Node *cnt) {
        printf("moved %d->%d to head\n", cnt->k, md[cnt->k]);
        Node *head = vhead->next;
        if (head == cnt) { return; }
        if (cnt->next != nullptr) {
            cnt->priv->next = cnt->next;
            cnt->next->priv = cnt->priv;
        }
        cnt->next = head;
        head->priv = cnt;
        vhead->next = cnt;
        cnt->priv = vhead;
    }
    
    void removeTail() {
        int k = vtail->priv->k;
        Node *l = vtail->priv;
        l->priv->next = vtail;
        vtail->priv = l->priv;
        printf("removed %d->%d\n", k, md[k]);
        md.erase(k);
        mn.erase(k);
        delete l;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
//    LRUCache c = LRUCache(2);
//    c.put(1, 1);
//    c.put(2, 2);
//    printf("%d\n", c.get(1));
//    c.put(3, 3);
//    printf("%d\n", c.get(2));
//    c.put(4, 4);
//    printf("%d\n", c.get(1));
//    printf("%d\n", c.get(3));
//    printf("%d\n", c.get(4));
    LRUCache c = LRUCache(1);
    c.put(2, 1);
    printf("%d\n", c.get(2));
    c.put(3, 2);
    printf("%d\n", c.get(2));
    printf("%d\n", c.get(3));
    return 0;
}
