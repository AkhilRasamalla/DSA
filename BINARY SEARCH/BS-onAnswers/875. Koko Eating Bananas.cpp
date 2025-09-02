class Solution {
private:
int findmaxi(vector<int>& v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]);

    }
    return maxi;

}
long long calculateTotalHours(vector<int>& v, int hourly) {  // Change return type to long long
    long long totalH = 0;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        totalH += ((long long)v[i] + hourly - 1) / hourly;
    }
    return totalH;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmaxi(piles);
        while(low <= high){
            int mid = (low+high)/2;
            // int totalH = calculateTotalHours(piles,mid);
            long long totalH = calculateTotalHours(piles, mid);  // Change to long long
            if(totalH <= h){
                high = mid-1;

            }
            else{
                low = mid+1;

            }
        }
        return low;
        
    }
};