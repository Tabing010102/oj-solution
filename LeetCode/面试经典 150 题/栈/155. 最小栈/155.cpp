#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v, minv;
    Node(int a, int b) : v(a), minv(b) {} 
};

inline int min(const int &a, const int &b) { return a < b ? a : b; }

class MinStack {
public:
    stack<Node> s;
    
    MinStack() {
        while (!s.empty()) { s.pop(); }
    }
    
    void push(int val) {
        if (s.empty()) { s.push(Node(val, val)); }
        else { s.push(Node(val, min(s.top().minv, val))); }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().v;
    }
    
    int getMin() {
        return s.top().minv;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack s;
    return 0;
}
