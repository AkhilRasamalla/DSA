class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
         int low = 0;
        int high = arr.size()-1;
        int mid ;
        int ans = INT_MAX;
        int index = -1;
        while(low<=high){
            mid = (low + high )/2;

            if(arr[low] <= arr[high]){
                if(arr[low] < ans){
                    index = low;
                    ans = arr[low];
                }
                break;

            }
            if(arr[low]<= arr[mid]){
                if(arr[low] < ans){
                    index = low;
                    ans = arr[low];
                }  
                low = mid+1;
            }
            else{
                
                high = mid-1;
                if(arr[mid] < ans){
                    index = mid;
                    ans = arr[low];
                }
            }
        }
        return index;
    }
};
