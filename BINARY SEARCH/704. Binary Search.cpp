class Solution {
// private:
// int bs(vector<int>& nums, int low , int high, int target){
//     if(low>high){
//         return -1;
//     }
//     int mid = low+{high/2);
//     if(nums[mid]==target){
//         return mid;
//     }
//     else if(target>nums[mid]){
//         return bs(nums,mid+1,high,target);
//     }
//     return bs(nums,low,mid-1,target);

// }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        //return bs(nums,0,n-1,target);;
        int low =0;
        int high = n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;

            }
            else if(target>nums[mid]){
               low=mid+1;
               

            }
            else
            high = mid-1;


        }
        return -1;
    }
};