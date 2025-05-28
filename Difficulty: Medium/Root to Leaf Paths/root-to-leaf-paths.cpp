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
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& temp){
        if(root == NULL){
            return;
        }
        temp.push_back(root->data);
        if(root->left == NULL and root->right == NULL){
            ans.push_back(temp);
        } 
        else{
            solve(root->left, ans, temp);
            solve(root->right, ans, temp);
        }
        temp.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, ans, temp);
        return ans;
    }
};