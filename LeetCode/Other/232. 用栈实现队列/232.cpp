#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
	stack<int> s1;
	stack<int> s2;
	
    MyQueue() {
		while (!s1.empty()) s1.pop();
		while (!s2.empty()) s2.pop();
    }
    
    void push(int x) {
		s1.push(x);
    }
    
    int pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int x = s1.top();
				s1.pop();
				s2.push(x);
			}
		}
		int x = s2.top();
		s2.pop();
		return x;
    }
    
    int peek() {
		int x = pop();
		s2.push(x);
		return x;
    }
    
    bool empty() {
		return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
	return 0;
}
