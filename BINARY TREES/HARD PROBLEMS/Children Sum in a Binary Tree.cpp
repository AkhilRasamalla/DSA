/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL){
            return 1;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
            
        }
        int leftVal = 0;
        int rightVal = 0;
        
        if(root->left != NULL){
            leftVal = root->left->data;
        }
        if(root->right != NULL){
            rightVal = root->right->data;
        }
        
        if(root->data != leftVal + rightVal){
            return false;
        }
        
        //subtrees
        int leftok = isSumProperty(root->left);
        int rightok = isSumProperty(root->right);
        
        return leftok && rightok;  // 1 if both are 1, else 0
        
    }
};