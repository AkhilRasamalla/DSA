class Solution {
  public:

    bool isPalindrome(string& s) {
        // code here
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            if(s[start] != s[end]){
                return 0;
                
            }
            start++;
            end--;
            
        }
        return 1;
        
    }
};