class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        // int ans = 1;
        // if(n==1){
        //     return ans;
        // }
        
        // for(int i=1;i<=n;i++){
        //     if(i*i <= n){
        //         ans= i;
                
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return ans;
        int low = 1;
        int high = n;
        while(low <= high ){
            int mid = (low+high)/2;
            int val = (mid*mid);
            if(val <= n){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};