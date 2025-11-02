class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        // Base condition
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through elements from current index to end
        for(int i = index; i < candidates.size(); i++) {
            // Skip duplicates (same element in same recursive level)
            if(i > index && candidates[i] == candidates[i-1]) continue;

            // If current number exceeds target, no need to proceed further
            if(candidates[i] > target) break;

            // Include current element
            ds.push_back(candidates[i]);

            // Recur for next index (i+1 since we can't reuse same element)
            solve(i + 1, candidates, target - candidates[i], ds, ans);

            // Backtrack - remove last element
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ds, ans);
        return ans;
    }
};
