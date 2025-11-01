class Solution {
  public:
    // Recursive function to generate all subset sums
    void solve(vector<int>& arr, int index, int currSum, vector<int>& result) {
        // Base case: when we've considered all elements
        if (index == arr.size()) {
            result.push_back(currSum);
            return;
        }

        // Choice 1: Include current element
        solve(arr, index + 1, currSum + arr[index], result);

        // Choice 2: Exclude current element
        solve(arr, index + 1, currSum, result);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        solve(arr, 0, 0, result);  // start with index=0, currentSum=0
        sort(result.begin(), result.end()); // sort the subset sums
        return result;
    }
};