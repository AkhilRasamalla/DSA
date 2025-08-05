

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        // vector<int> ans;
        // int n = arr.size();
        // for(int i=0;i<n;i++){
        //     bool isleader = true;
        //     for(int j=i+1;j<n;j++){
        //         if(arr[j]>arr[i]){
        //             isleader=false;
        //             break;
        //         }
        //     }
        //     if(isleader){
        //         ans.push_back(arr[i]);
        //     }
        // }
        
        
        // return ans;
        
        vector<int> ans;
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                
            }
            //keep  the right track of max
            maxi = max(maxi,arr[i]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};