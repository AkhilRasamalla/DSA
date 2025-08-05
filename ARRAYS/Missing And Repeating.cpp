class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int  n= arr.size();
        long long sum_n = (long long)n*(n+1)/2;
        long long sum_sq_n = (long long)n*(n+1)*(2*n+1)/6;
        
        long long sum1 = 0;
        long long sum2 = 0;
        
        for(int i=0;i<n;i++){
            sum1 += arr[i];
            sum2 += (long long)arr[i]*arr[i];
            
        }
        long long diff = sum1-sum_n;
        long long sqdiff = sum2-sum_sq_n;
        
        long long sumXY = sqdiff/diff;
        int X = (diff+sumXY)/2;
        int Y = X - diff;
        return{X,Y};
        
    }
};