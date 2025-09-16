class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l = 0;
        unordered_map<char,int>freq;
        int maxLen = -1;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            while(freq.size() > k){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            if(freq.size() == k){
                maxLen = max(maxLen, r-l+1);
            }
        }
        return maxLen;
    }
};