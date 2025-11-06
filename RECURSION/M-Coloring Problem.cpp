class Solution {
  public:
    // Function to check if we can color a node with a given color
    bool isSafe(int node, int color[], vector<vector<int>> &adj, int col) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) return false;
        }
        return true;
    }

    // Recursive function to try coloring each node
    bool solve(int node, int color[], int m, int v, vector<vector<int>> &adj) {
        if (node == v) return true; // base case: all nodes colored

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, adj, col)) {
                color[node] = col;
                if (solve(node + 1, color, m, v, adj)) return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // ✅ Step 1: Build adjacency list from edge pairs
        vector<vector<int>> adj(v);
        for (auto &e : edges) {
            int u = e[0], w = e[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        // ✅ Step 2: Initialize color array
        int color[v] = {0};

        // ✅ Step 3: Run backtracking
        return solve(0, color, m, v, adj);
    }
};
