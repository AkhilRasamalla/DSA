class Solution {
public:
    bool checkValidString(string s) {
        int maxi = 0;
        int mini = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == ')') {
                mini--;
                maxi--;
            } else {
                mini = mini - 1;
                maxi = maxi + 1;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }
        return mini==0;
    }
};