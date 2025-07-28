class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int maxi = 0;
        int i = 0;//arr[0];
        int j = 0;//arr[0];
        int sum = 0;
        while(j<arr.size()){
            sum = sum + arr[j];
            if(j-i+1<k)
            j++;
            else if(j-i+1 == k){
                maxi = max(maxi,sum);
                sum = sum - arr[i];
                i++;
                j++;
                
            }
        }
        return maxi;
        
    }
};