class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;   // build histogram height
                } else {
                    heights[j] = 0;    // reset when '0'
                }
            }

            // compute max rectangle for this row histogram
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
