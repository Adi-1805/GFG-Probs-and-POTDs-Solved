/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class BSTIterator {
public:
    stack<Node*> st;
    BSTIterator(Node* root){
        pushAllRight(root);
    }
    
    int prev(){
        Node* root = st.top();
        st.pop();
        pushAllRight(root->left);
        return root->data;
    }
    
    void pushAllRight(Node* root){
        if(!root) return;
        Node* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->right;
        }
    }
    
    bool hasPrev(){
        return !st.empty();
    }
};
class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        BSTIterator it(root);
        int ans = -1;
        while(it.hasPrev() and k>0){
            k--; ans = it.prev();
        }
        return ans;
    }
};