class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // initialize with -1
        stack<int> st;            // stores indices

        // Loop from 2n-1 to 0 to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Pop elements smaller or equal to current
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            // Assign the next greater if stack is not empty
            if (!st.empty()) {
                ans[idx] = nums[st.top()];
            }

            // Push current index to stack
            st.push(idx);
        }

        return ans;
    }
};
