/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    bool isLeaf(Node *node) {
        return node && !node->left && !node->right;
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        if (!isLeaf(root)) ans.push_back(root->data);

        addleft(root, ans);
        addleaf(root, ans);     // MUST come before addright
        addright(root, ans);

        return ans;
    }

    void addleft(Node* root, vector<int>& ans) {
        Node* curr = root->left;  // FIXED
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data); // FIXED
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addright(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        vector<int> temp;  // FIXED
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data); // FIXED
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    void addleaf(Node* root, vector<int>& ans) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addleaf(root->left, ans);
        if (root->right) addleaf(root->right, ans); // FIXED
    }
};
