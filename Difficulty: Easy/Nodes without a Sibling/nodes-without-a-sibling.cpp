/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void noSibs(Node* root, vector<int>& ans){
    if(!root) return ;
    if(root->left and !root->right){
        ans.push_back(root->left->data);
    }
    if(!root->left and root->right){
        ans.push_back(root->right->data);
    }
    
    noSibs(root->left, ans);
    noSibs(root->right, ans);
}


vector<int> noSibling(Node* node) {
    // code here
    if(!node) return {-1};
    vector<int> ans;
    noSibs(node, ans);
    if(ans.size() == 0) return {-1};
    sort(ans.begin(), ans.end());
    return ans;
    
}