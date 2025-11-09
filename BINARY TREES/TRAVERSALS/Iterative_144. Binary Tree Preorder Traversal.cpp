/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preorder(root,ans);
//         return ans;
//     }
//     void preorder(TreeNode* root,vector<int>& ans){
//         if(root == nullptr)
//         return;
//         ans.push_back(root->val); //root
//         preorder(root->left,ans); //left
//         preorder(root->right,ans); //right

//     }
// };
#include <vector>
#include <stack>
using namespace std;

// TreeNode is predefined in LeetCode.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            result.push_back(node->val);  // Visit root first

            // Push right child first so that left is processed first
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }
};

