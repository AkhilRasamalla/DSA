class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mpp;

        for(int i = 0; i<n;i++)
        {
            int memory = target - nums[i];
            if(mpp.find(memory) != mpp.end())
            {
                return{mpp[memory],i};

            }
            else{
                mpp[nums[i]]=i;

            }
            
        }
        return{};
             
    }
};