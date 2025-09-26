// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.size();
//         int i = 0;

//         // calculate the leading white spaces
//         while (i < n && s[i] == ' ') {
//             i++;
//         }
//         // check for sign
//         int sign = 1;
//         if (s[i] == '-' || s[i] == '+') {
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;
//         }
//         // read digits
//         long num = 0;
//         while (i < n && isdigit(s[i])) {
//             int digit = s[i] - '0';
//             num = num * 10 + digit;

//             // 4. Check for overflow and clamp
//             if (sign == 1 && num > INT_MAX)
//                 return INT_MAX;
//             if (sign == -1 && -num < INT_MIN)
//                 return INT_MIN;

//             i++;
//         }
//         return (int)(sign * num);
//     }
// };


class Solution {
public:
    int myAtoi(string s) {
        return helper(s, 0, 1, 0, false);
    }

private:
    int helper(const string &s, int index, int sign, long num, bool started) {
        // Base case: reached end of string
        if (index == s.size()) return sign * num;

        char c = s[index];

        // Case 1: Leading spaces
        if (!started && c == ' ') {
            return helper(s, index + 1, sign, num, started);
        }

        // Case 2: Sign
        if (!started && (c == '+' || c == '-')) {
            int newSign = (c == '-') ? -1 : 1;
            return helper(s, index + 1, newSign, num, true);
        }

        // Case 3: Digit
        if (isdigit(c)) {
            num = num * 10 + (c - '0');

            // Clamp to 32-bit signed integer
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            return helper(s, index + 1, sign, num, true);
        }

        // Case 4: Non-digit character after starting parsing
        return sign * num;
    }
};