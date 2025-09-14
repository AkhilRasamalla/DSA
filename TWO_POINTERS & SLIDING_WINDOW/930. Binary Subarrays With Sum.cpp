class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int n = nums.size();
        // //int maxi = 0;
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum = sum + nums[j];
        //         // if(sum <= goal){
        //         //     maxi = max(maxi,j-i+1);
        //         // }
        //         // else{
        //         //     break;
        //         // }
        //         if(sum == goal){
        //             count++;
        //         }
        //         if(sum>goal){
        //             break;
        //         }
        //     }
        // }
        // return count;

        unordered_map<int,int> freq;
        freq[0]=1;
        int prefixSum = 0, count  = 0;
        for(int num : nums){
            prefixSum += num;

        
        if(freq.find(prefixSum -goal) != freq.end()){
            count += freq[prefixSum-goal];
        }

        freq[prefixSum]++;
        }

        return count;


    }
};