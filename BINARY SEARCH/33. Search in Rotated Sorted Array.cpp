class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int ans = -1;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid]== target)
            return mid;
            // check the half is sorted

            //left sorted 
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    //eliminate right half
                    high = mid-1;
                }
                else{
                    //eliminate left half
                    low = mid+1;
                }
            }
            //right sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    //left
                    low = mid + 1;

                }
                else{
                    //right
                    high = mid -1;
                }
            }
           //return mid ;
        }
        return -1;
        
    }
};