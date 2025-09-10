#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getPrevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    vector<int> getNextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left = getPrevSmaller(arr);
        vector<int> right = getNextSmaller(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
            ans = (ans + contrib) % MOD;
        }

        return (int)ans;
    }
};


