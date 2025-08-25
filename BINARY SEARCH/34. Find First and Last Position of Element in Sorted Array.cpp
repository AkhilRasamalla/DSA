class Solution {
private:
    int FirstPosition(vector<int>& nums, int target) {
        int first = -1;
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    int LastPosition(vector<int>& nums, int target) {
        int last = -1;
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FirstPosition(nums, target);
        if (first == -1) return {-1,-1};
        int last = LastPosition(nums, target);
        return {first, last};
    }
};