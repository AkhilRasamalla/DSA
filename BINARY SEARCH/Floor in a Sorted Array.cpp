class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        // int count = 0;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i] <= x){
        //         count++;
        //     }
        //     else {
        //         break;
        //     }
             
        // }
        // int ans = count-1;
        // if (ans <0){
        //     return -1;
            
        // }
        // return ans;
        int low = 0;
        int high = arr.size()-1;
        int mid ;
        while(low <= high ){
            mid = low + (high-low)/2;
            if(arr[mid]<=x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    
    
    }
};
