class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 0; i<n;i++)
        // {
        //     if(nums[i] != i)
        //     {
        //         return i;

        //     }
        // }
        // return n;


        // int n = nums.size();
        // unordered_set<int> st(nums.begin(), nums.end());
        // for(int i=0;i<=n;i++)
        // {
        //     if(st.find(i) != st.end())
        //     {
        //         return i;

        //     }
        // }
        // return -1;

        int n = nums.size();
        int expected_sum = n*(n+1)/2;
        int actual_sum = 0;
        for(int i =0;i<n;i++)
        {
            actual_sum  += nums[i];



        }
        int missing = expected_sum - actual_sum;
        return missing;
        


    }
};