#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;      // main stack
    stack<int> minSt;   // stack to track minimum

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        // if minSt is empty or new val <= current min, push into minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        int topVal = st.top();
        st.pop();
        // if popped element is also minimum, pop from minSt
        if (!minSt.empty() && topVal == minSt.top()) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
