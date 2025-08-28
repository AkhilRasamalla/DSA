class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low = 0;
        // int high = nums.size()-1;
        // int mid;
        // if(nums[low] <= nums[high]){
        //     return nums[0];
        // }
        // while(low <= high){
        //     mid = (low+high)/2;
        //     if(mid < high && nums[mid] > nums[mid+1]){
        //         return nums[mid+1];
        //     }
        //     if(mid > low && nums[mid] < nums[mid-1]){
        //         return nums[mid];

        //     }
        //     if(nums[high] > nums[mid]){
        //         high =  mid -1;
        //     }
        //     else{
        //         low = mid+1;
        //     }
        // }
        // return -1;


        // another comparison 
        int low = 0;
        int high = nums.size()-1;
        int mid ;
        int ans = INT_MAX;
        while(low<=high){
            mid = (low + high )/2;

            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;

            }
            if(nums[low]<= nums[mid]){
                ans = min(ans ,nums[low]);
                low = mid+1;
            }
            else{
                high = mid-1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;

    }
};