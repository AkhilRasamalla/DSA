class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        // pair of {end, start}
        vector<pair<int,int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // sort by end time
        sort(meetings.begin(), meetings.end());

        int count = 1; // pick the first meeting
        int last_end = meetings[0].first;

        for (int i = 1; i < n; i++) {
            if (meetings[i].second > last_end) { // check start > last_end
                count++;
                last_end = meetings[i].first;
            }
        }

        return count;
    }
};
