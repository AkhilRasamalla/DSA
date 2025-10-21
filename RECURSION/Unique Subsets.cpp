
class Solution {
  public:
    void solve(vector<int> ip, vector<int> op, vector<vector<int>>& ans) {
        // Base condition
        if (ip.size() == 0) {
            ans.push_back(op);
            return;
        }

        // Copy output for two recursive calls
        vector<int> op1 = op;
        vector<int> op2 = op;

        // Include current element in op2
        op2.push_back(ip[0]);

        // Remove processed element
        ip.erase(ip.begin());

        // Recursive calls
        solve(ip, op1, ans);  // exclude
        solve(ip, op2, ans);  // include
    }

    vector<vector<int>> AllSubsets(vector<int> arr, int N) {
        vector<vector<int>> ans;
        vector<int> op;

        sort(arr.begin(), arr.end()); // to handle duplicates properly

        solve(arr, op, ans);

        // Remove duplicates using set
        set<vector<int>> st(ans.begin(), ans.end());

        ans.assign(st.begin(), st.end()); // convert back to vector

        return ans;
    }
};