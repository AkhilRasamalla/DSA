#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // 1. Remove indices that are out of this window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Window is valid, record max
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
