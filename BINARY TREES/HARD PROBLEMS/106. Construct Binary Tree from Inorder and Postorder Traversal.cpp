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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        return buildtree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1, mpp);
    }

    TreeNode* buildtree(vector<int>& inorder, int instart, int inend,
                        vector<int>& postorder, int pstart, int pend,
                        map<int,int>& mpp){

        if(pstart > pend || instart > inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pend]);
        int inRoot = mpp[postorder[pend]];

        int numsleft = inRoot - instart;

        root->left = buildtree(inorder, instart, inRoot - 1,
                               postorder, pstart, pstart + numsleft - 1, mpp);

        root->right = buildtree(inorder, inRoot + 1, inend,
                                postorder, pstart + numsleft, pend - 1, mpp);

        return root;
    }
};
