class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool checkBST(Node* root, int lval, int rval){
        if(!root) return true;
        
        return (lval < root->data and root->data < rval and checkBST(root->left, lval, root->data) and checkBST(root->right, root->data, rval));
        
    }
    bool isBST(Node* root) {
        // Your code here
        int lval = -1e9, rval = 1e9;
        return checkBST(root, lval, rval);
    }
};