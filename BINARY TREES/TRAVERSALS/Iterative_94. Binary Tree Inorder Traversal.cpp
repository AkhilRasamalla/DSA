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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         Inorder(root,ans);
//         return ans;
//     }
//     void Inorder(TreeNode* root,vector<int>& ans){
//         if(root == nullptr)
//         return;
//         Inorder(root->left,ans); //left
//         ans.push_back(root->val); //root
//         Inorder(root->right,ans); //right

//     }
// };
// LeetCode provides TreeNode definition.
// Just submit this class.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // 1) Go left as far as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 2) Visit node
            curr = st.top(); st.pop();
            result.push_back(curr->val);

            // 3) Then go right
            curr = curr->right;
        }
        return result;
    }
};
