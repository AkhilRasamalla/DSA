class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int zeroes = 0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0) zeroes++;
        //         if(zeroes <= k){
        //             maxi = max(maxi,j-i+1);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxi;

        int l = 0;
        int r = 0;
        int zeros = 0;
        while (r < n) {

            if (nums[r] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};