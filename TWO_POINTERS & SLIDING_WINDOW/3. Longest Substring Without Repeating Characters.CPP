class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // int n = s.size();
        // int maxLen = 0;
        // for(int i=0;i<n;i++){
        //     unordered_set<char> seen;
        //     for(int j=i;j<n;j++){
        //         if(seen.find(s[j]) != seen.end())
        //         break;
        //         else{
        //             seen.insert(s[j]);
        //             int currentElement = j-i+1;
        //             maxLen = max(maxLen,currentElement);

        //         }
        //     }
        // }
        // return maxLen;

        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_set<int> seen;
        while (r < n)
        {
            if (seen.find(s[r]) != seen.end())
            {
                seen.erase(s[l]);
                l++;
            }
            else
            {
                seen.insert(s[r]);
                int currentElement = r - l + 1;
                maxLen = max(maxLen, currentElement);
                r++;
            }
            // r++;
        }
        return maxLen;
    }
};