class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        // Loop runs one extra step to handle remaining bars
        for (int i = 0; i <= n; i++) {
            int currHeight;
            if (i == n) {
                currHeight = 0;  // sentinel height for cleanup
            } else {
                currHeight = heights[i];
            }

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;   // all bars till i are taller
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }

            st.push(i);
        }

        return maxArea;
    }
};
