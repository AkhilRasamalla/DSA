class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int low = 0;
        int high = nums.size()-1;
        int mid;
        int ans = -1;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid]== target)
            return true;

            /// the modification shrink it 
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low = low+1;
                high = high-1;
                continue;
            }

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
        return false;
    }
};