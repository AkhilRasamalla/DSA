class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> count(n, 0);
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            int cnt = 0;

            // Temporary stack to hold popped elements
            stack<int> temp;

            // Count elements greater than arr[i]
            while(!st.empty()) {
                if(st.top() > arr[i]) {
                    cnt++;
                }
                temp.push(st.top());
                st.pop();
            }

            // Restore original stack
            while(!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }

            // Push current element
            st.push(arr[i]);

            count[i] = cnt;
        }

        // Prepare results for queries
        vector<int> result;
        for(int idx : indices)
            result.push_back(count[idx]);

        return result;
    }
};
