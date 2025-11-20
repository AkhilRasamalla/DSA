/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  vector<vector<int>> ans;
    vector<vector<int>> Paths(Node* root) {
        // code here
        //vector<vector<int>> ans
        vector<int>path;
        dfs(root,path);
        return ans;
    }
    void dfs(Node* root,vector<int>& path){
        if(!root) return;
        path.push_back(root->data);//include curr data;
        
        if(!root->left && !root->right){//leaf->safe path
            ans.push_back(path);
        }
        
        dfs(root->left,path);
        dfs(root->right,path);
        
        path.pop_back();
    }
};