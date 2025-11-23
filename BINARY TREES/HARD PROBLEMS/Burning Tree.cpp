class Solution {
public:

    // Step 1: Map each node to its parent
    void markParents(Node* root, unordered_map<Node*, Node*>& parentTrack, Node* &targetNode, int target) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target)
                targetNode = current;

            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        if (!root) return 0;

        unordered_map<Node*, Node*> parentTrack;
        Node* targetNode = NULL;

        // Step 2: Store parents and find target node
        markParents(root, parentTrack, targetNode, target);

        // Step 3: BFS to burn tree
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // Left
                if (node->left && !visited[node->left]) {
                    burned = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Right
                if (node->right && !visited[node->right]) {
                    burned = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Parent
                if (parentTrack[node] && !visited[parentTrack[node]]) {
                    burned = true;
                    visited[parentTrack[node]] = true;
                    q.push(parentTrack[node]);
                }
            }

            if (burned) time++;
        }

        return time;
    }
};
