// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    int mx = -1e9;
    int pathSum(Node *root){
        if(!root) return 0;
        
        int l = max(0, pathSum(root->left));
        int r = max(0, pathSum(root->right));
        
        // calculates maxpathsum you can get out of a subtree
        mx = max(mx, root->data + l + r); 
        
        return root->data + max(l, r); // returns maxpathsum
        
    }
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        pathSum(root);
        return mx;
    }
};