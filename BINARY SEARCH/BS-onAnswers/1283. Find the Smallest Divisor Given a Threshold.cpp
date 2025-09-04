class Solution {
private:
int divideD(vector<int>& nums,int Div){
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
       sum += ceil((double)nums[i] / (double)Div);  // type cast + ceil


    }
    return sum;

}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int low = 1;
        int ans = -1;
        // max of the array element
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = (low+high)/2;
            if(divideD(nums,mid) <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;

    }
};