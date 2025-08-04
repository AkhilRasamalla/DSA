class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int n = arr.size();
        int countOnes = 0, countZeros = 0;
        int maxOnes = 0, maxZeros = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1){
                countOnes++;
                countZeros = 0;
                
            }
            else{
                countZeros++;
                countOnes = 0;
                
            }
            maxOnes = max(maxOnes, countOnes);
            maxZeros = max(maxZeros, countZeros);
            
        }
        return max(maxOnes, maxZeros);

    }
};