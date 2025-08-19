/*
// Tree Node
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
    vector<int> ans;
    
    void leftWithoutLeaf(Node* root){
        if(!root or (!root->left and !root->right)) return ;
        
        ans.push_back(root->data);
        if(root->left) leftWithoutLeaf(root->left);
        else leftWithoutLeaf(root->right);
        
    }
    void rightWithoutLeaf(Node* root){
        if(!root or (!root->left and !root->right)) return ;
        
        if(root->right) rightWithoutLeaf(root->right);
        else rightWithoutLeaf(root->left);
        ans.push_back(root->data);
        
    }
    void leaves(Node* root){
        if(!root) return ;
        
        if(!root->left and !root->right) {
            ans.push_back(root->data);
            return ;
        }
        
        leaves(root->left);
        leaves(root->right);
        
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return {};
        
        // pushing the root in ans vector only when it is not a leaf node
        if(root->left or root->right) ans.push_back(root->data); 
        
        leftWithoutLeaf(root->left);
        
        leaves(root);
        
        rightWithoutLeaf(root->right);
        
        return ans;
        
    }
};