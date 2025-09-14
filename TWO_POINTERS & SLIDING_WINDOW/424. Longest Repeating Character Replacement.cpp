class Solution {
public:
    int characterReplacement(string s, int k) {
        // int n = s.size();
        // int maxi =0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> count;
        //     int maxfreq=0;
        //     for(int j=i;j<n;j++){
        //         count[s[j]]++;
        //         //iterate the map
        //         unordered_map<char,int>:: iterator it;
        //         for(it=count.begin(); it != count.end();it++){
        //             if(it->second > maxfreq){
        //                 maxfreq = it->second;
        //             }
        //         }
        //         int windowsize = j-i+1;
        //         int replacement = windowsize-maxfreq;

        //         if(replacement <= k){
        //             if(windowsize > maxi){
        //                 maxi = windowsize;
        //             }
        //         }
        //     }
        // }
        // return maxi;

        int l = 0;
        int r = 0;
        int maxlen = 0,maxfreq=0;
        int n = s.size();
        int count[26] = {0};
        for(r=0;r<n;r++){
            count[s[r]-'A']++;
            if(count[s[r]-'A']>maxfreq){
                maxfreq = count[s[r]-'A'];
            }
            int windowsize = r-l+1;
            int replacement = windowsize -maxfreq;

            if(replacement > k){
                count[s[l]-'A']--;
                l++;
            }
            windowsize = r-l+1;
            if(windowsize > maxlen){
                maxlen = windowsize;
            }

        }
        return maxlen;
    }
};