class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int count=0;

        //     for(int j=0;j<n;j++){
        //         if(nums[i]==nums[j])
        //         count++;
                
        //     }
        //     if(count==1){
        //         return nums[i];

        //     }
        // }
        // return -1;

        // unordered_map<int,int>freq;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     freq[nums[i]]++;
        // }
        // for(auto it : freq ){
        //     if(it.second==1){
        //         return it.first;

        //     }
        // }
        // return -1;

        int n =nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            result ^= nums[i];
        }
        return result;


    }
};