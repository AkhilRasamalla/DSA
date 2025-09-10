class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                    continue;
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed)
                st.push(a);
        }
        int n = st.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};