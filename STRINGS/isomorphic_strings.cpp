class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t, t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char ch_s = s[i];
            char ch_t = t[i];

            // Check s -> t mapping
            if (s_to_t.count(ch_s)) {
                if (s_to_t[ch_s] != ch_t) return false;
            } else {
                s_to_t[ch_s] = ch_t;
            }

            // Check t -> s mapping
            if (t_to_s.count(ch_t)) {
                if (t_to_s[ch_t] != ch_s) return false;
            } else {
                t_to_s[ch_t] = ch_s;
            }
        }

        return true;
    }
};
