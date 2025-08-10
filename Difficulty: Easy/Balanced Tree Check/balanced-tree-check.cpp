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
    int ht(Node* root){
        if(!root) return 0;
        
        int lh = ht(root->left);
        int rh = ht(root->right);
        
        if(lh == -1 or rh == -1) return -1;
        if(abs(rh-lh) > 1) return -1;
        
        return 1 + max(lh, rh);
    }
  public:
    bool isBalanced(Node* root) {
        // Code here
        return (ht(root) != -1);
        
    }
};