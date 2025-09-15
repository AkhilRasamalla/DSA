class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0;
        int cnt = 0;
        int odds = 0;
        for (int r = 0; r < nums.size(); r++) {
            odds += nums[r] % 2; // odd =1 or even = 2;
                    while (odds > k) {
                odds -= nums[l] % 2;
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int n = nums.size();
        // // int cnt  = 0;
        // // for(int i=0;i<n;i++){
        // //     int OddCount = 0;
        // //     for(int j=i;j<n;j++){
        // //         if(nums[j] % 2 != 0 ) OddCount++;
        // //         if(OddCount == k) cnt++;
        // //         else if (OddCount > k) break;
        // //     }

        // // }
        // return cnt;

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};