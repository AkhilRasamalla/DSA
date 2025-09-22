class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by ending time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int count = 0;  // number of non-overlapping intervals we keep
        int end = INT_MIN;

        for (auto &interval : intervals) {
            if (interval[0] >= end) {
                // no overlap → keep it
                count++;
                end = interval[1];
            }
        }

        return intervals.size() - count; // remove the rest
    }
};
