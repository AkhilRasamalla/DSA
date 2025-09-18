class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // vector of {ratio, weight, value}
        vector<pair<double, pair<int,int>>> items;
        for(int i=0;i<n;i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {wt[i], val[i]}});
        }

        // sort by ratio in descending order
        sort(items.rbegin(), items.rend());

        double totalValue = 0.0;
        for(int i=0;i<n && capacity>0;i++) {
            int weight = items[i].second.first;
            int value = items[i].second.second;

            if(weight <= capacity) {
                // take whole item
                totalValue += value;
                capacity -= weight;
            } else {
                // take fraction
                totalValue += items[i].first * capacity;
                break;
            }
        }

        return totalValue;
    }
};
