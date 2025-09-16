class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        unordered_map<int, int> freq;   // use int, not char

        for (int r = 0; r < n; r++) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
};
