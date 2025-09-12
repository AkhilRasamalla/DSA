#include <bits/stdc++.h>
using namespace std;

class Solution {
    // ---------- Minimum ----------
    vector<int> getPrevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // For MIN: use '>' here
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
            // For MIN: use '>=' here
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    // ---------- Maximum ----------
    vector<int> getPrevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // For MAX: use '<' instead of '>'
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    vector<int> getNextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // For MAX: use '<=' instead of '>='
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

public:
    long long subarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = getPrevSmaller(arr);
        vector<int> right = getNextSmaller(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * arr[i] * left[i] * right[i];
        }
        return ans;
    }

    long long subarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = getPrevGreater(arr);
        vector<int> right = getNextGreater(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * arr[i] * left[i] * right[i];
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarrayMaxs(nums) - subarrayMins(nums);
    }
};
