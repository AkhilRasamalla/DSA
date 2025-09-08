#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    vector<int> st;

public:
    // Push operation
    void push(int x) {
        st.push_back(x);
    }

    // Pop operation
    int pop() {
        if (st.empty()) return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }
};

vector<int> stackOperations(vector<int>& oper) {
    MyStack s;
    vector<int> result;

    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == 1) {           // push
            i++;                      // next element is the value
            s.push(oper[i]);
        } else if (oper[i] == 2) {    // pop
            result.push_back(s.pop());
        }
    }
    return result;
}