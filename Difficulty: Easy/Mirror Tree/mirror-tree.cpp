/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    void solve(Node* root){
        if(root == NULL) return;
        
        solve(root->left);
        solve(root->right);
        
        swap(root->left, root->right);
        
    }
  public:
    void mirror(Node* node) {
        // code here
        Node *ans = node;
        solve(ans);
        node = ans;
    }
};