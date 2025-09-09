class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            // Pop all elements >= arr[i]
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack is not empty, top is next smaller to right
            if(!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element for future comparison
            st.push(arr[i]);
        }

        return ans;
    }
};
