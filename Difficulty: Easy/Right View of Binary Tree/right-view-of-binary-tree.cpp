/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
    vector<int> ans;
    // REVERSE PREORDER: Root -> Right -> Left
    void reverse_preorder(Node* root, int level){
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->data); // for each level there will be one value added to ans, hence this will ensure that for each level the first node traversed is pushed in ans
        reverse_preorder(root->right, level+1);
        reverse_preorder(root->left, level+1); 
    }
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        reverse_preorder(root, 0);
        return ans;
    }
};