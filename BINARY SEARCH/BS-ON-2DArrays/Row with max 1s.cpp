
class Solution {
private:
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
    
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
     int n = arr.size();        // number of rows
    int m = arr[0].size();     // number of columns
        
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
         int cnt_ones = m - lowerBound(arr[i], 1);
;
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
        
    }
};