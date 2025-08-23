class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();  // default: not found
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;      // candidate index
            high = mid - 1; // check if there's a smaller index
        } else {
            low = mid + 1;
        }
    }
    return ans;
    }
};
