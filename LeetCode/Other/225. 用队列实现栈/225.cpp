#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
	queue<int> q; 
    MyStack() {
		while (!q.empty()) { q.pop(); }
    }
    
    void push(int x) {
		q.push(x);
    }
    
    int pop() {
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		int x = q.front();
		q.pop();
		return x;
    }
    
    int top() {
    	int x = pop();
    	q.push(x);
    	return x;
    }
    
    bool empty() {
		return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	return 0;
}
 
