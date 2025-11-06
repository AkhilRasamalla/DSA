class Solution {
public:
    void solve(int index, string s, unordered_set<string>& dict,
               vector<string>& result, string current) {
        // base case: reached end of string
        if (index == s.size()) {
            current.pop_back(); // remove last space
            result.push_back(current);
            return;
        }

        string word = "";
        // explore all substrings starting at index
        for (int i = index; i < s.size(); i++) {
            word += s[i];
            if (dict.find(word) != dict.end()) {
                solve(i + 1, s, dict, result, current + word + " ");
            }
        }
    }

    vector<string> wordBreak(vector<string>& wordDict, string s) { // ✅ swapped params
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> result;
        solve(0, s, dict, result, "");
        return result;
    }
};
