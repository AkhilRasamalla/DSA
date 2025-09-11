class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;   // stack to maintain digits in increasing order
        int n = num.size();
        
        // iterate through all digits
        for (int i = 0; i < n; i++) {
            // while we can still remove digits (k > 0)
            // and the top of stack is bigger than current digit
            // remove it (to get smaller number)
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();   // remove larger digit
                k--;        // one removal done
            }
            st.push(num[i]);   // push current digit into stack
        }

        // if still removals are left, remove from the end (largest digits at the end)
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // if stack becomes empty, result is just "0"
        if (st.empty()) return "0";

        // collect digits from stack into a string (stack is LIFO, so digits are reversed)
        string res;
        while (!st.empty()) {
            res.push_back(st.top());  // add top element
            st.pop();                 // remove it
        }

        // remove leading zeros from the number (but keep at least one digit)
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }

        // digits are in reverse order (because of stack),
        // so reverse them to get correct number
        reverse(res.begin(), res.end());

        // if result is empty after cleaning, return "0"
        if (res.empty()) return "0";
        
        return res;   // final smallest number after removing k digits
    }
};
