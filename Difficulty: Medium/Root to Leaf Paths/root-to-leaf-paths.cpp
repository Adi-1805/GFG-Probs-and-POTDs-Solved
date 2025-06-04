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
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(Node* root){
        if(root == NULL){
            return;
        }
        temp.push_back(root->data);
        if(root->left == NULL and root->right == NULL){
            ans.push_back(temp); 
        } 
    
        solve(root->left);
        solve(root->right);
    
        temp.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        solve(root);
        return ans;
    }
};