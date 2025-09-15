class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> freq;
        //     for(int j=i;j<n;j++){
        //         freq[s[j]]++;
        //         if(freq.size() ==3){
        //             cnt += (n-j);
        //             break;
        //         }
        //     }
        // }

        ///OPTIMAL
        // vector<int> count(3, 0);
        // int l = 0;
        // for (int r = 0; r < n; r++) {
        //     count[s[r] - 'a']++;
        //     while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        //         count[s[l] - 'a']--;
        //         l++;
        //     }
        //     cnt += l; // all substrings ending at r that are valid
        // }
        // return cnt;

        vector<int> last(3,-1);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                cnt += 1 + min({last[0],last[1],last[2]});

            }
        }
        return cnt;
    }
};