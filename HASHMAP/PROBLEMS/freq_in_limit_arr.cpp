class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
       
    int n = arr.size();
    
    // Step 1: Create hash map to count frequencies
    unordered_map<int, int> hash;
    
    // Step 2: Count frequencies using hash map
    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    
    // Step 3: Create result array and fill from hash map
    vector<int> result(n, 0);
    for(int i = 1; i <= n; i++) {
        if(hash.find(i) != hash.end()) {
            result[i-1] = hash[i];  // i-1 because result is 0-indexed
        }
        // If number i is not found, result[i-1] remains 0
    }
    
    return result;

        
        
    }
};
