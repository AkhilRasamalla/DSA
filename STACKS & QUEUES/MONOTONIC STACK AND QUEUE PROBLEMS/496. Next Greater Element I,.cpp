#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>Ngreater;
        stack<int> st;

        for (int i = nums2.size()-1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            if (st.empty()) {
                Ngreater[num] = -1;
            } else {
                Ngreater[num] = st.top();
            }
            st.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(Ngreater[num]);
        }
        return ans;
    }
};
