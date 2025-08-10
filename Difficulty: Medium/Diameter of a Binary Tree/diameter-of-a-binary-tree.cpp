/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
    int diam = 0;
    int ht(Node *root){
        if(!root) return 0;
        int lh = ht(root->left), rh = ht(root->right);
        diam = max(diam, lh + rh);
        return 1 + max(lh, rh);
    }
  public:
    int diameter(Node* root) {
        // Your code here
        ht(root);
        return diam;
    }
};