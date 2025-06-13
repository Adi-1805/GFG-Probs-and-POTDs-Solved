// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        if(!root) return -1;
        int ans = -1;
        Node* temp = root;
        while(temp){
            if(temp->data <= x){
                ans = temp->data;
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        return ans;
    }
};