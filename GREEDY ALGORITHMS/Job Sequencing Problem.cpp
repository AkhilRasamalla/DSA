class Solution {
public:
    vector<int> parent;

    // DSU find function with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        // Step 1: Store jobs as (profit, deadline)
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Step 3: Find maximum deadline
        int maxDeadline = 0;
        for (auto &job : jobs) {
            maxDeadline = max(maxDeadline, job.second);
        }

        // Step 4: Initialize DSU parent array
        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int totalProfit = 0, countJobs = 0;

        // Step 5: Assign jobs using DSU
        for (auto &job : jobs) {
            int currProfit = job.first;
            int currDeadline = job.second;

            // Find the latest free slot available <= deadline
            int availableSlot = find(currDeadline);

            if (availableSlot > 0) {
                // Schedule job
                totalProfit += currProfit;
                countJobs++;
                // Mark this slot as occupied -> link to previous free slot
                parent[availableSlot] = find(availableSlot - 1);
            }
        }

        return {countJobs, totalProfit};
    }
};
