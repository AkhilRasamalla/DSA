/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // DFS ROOT-RIGHT-LEFT
    //  vector<int> rightSideView(TreeNode* root) {
    //      vector<int> ans;
    //      dfs(root,0,ans);
    //      return ans;
    //  }
    //  void dfs(TreeNode* root,int level,vector<int>& ans){
    //      if(!root) return ;

    //     if(level==ans.size()) ans.push_back(root->val);

    //     dfs(root->right,level+1,ans);
    //     dfs(root->left,level+1,ans);

    // }
    // LEVEL ORDER TRAVERSALS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeNode* node;
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};