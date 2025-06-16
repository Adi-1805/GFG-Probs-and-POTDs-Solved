/*
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
class BSTIterator {
public:
    stack<Node*> st;
    void pushAllLeft(Node* root){
        if(!root) return ;
        Node* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->left;
        } 
    }
    BSTIterator(Node* root){
        pushAllLeft(root); 
    }
    int next() {
        Node* root = st.top();
        st.pop();
        pushAllLeft(root->right);
        return root->data;
    }
    bool hasNext(){
        return (!st.empty());
    } 
};
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        BSTIterator it1(root1);
        BSTIterator it2(root2);
        vector<int> ans;
        
        while(it1.hasNext() and it2.hasNext()){
            int val1 = it1.st.top() -> data;
            int val2 = it2.st.top() -> data;
            
            if(val1 <= val2){
                ans.push_back(it1.next());
            }else{
                ans.push_back(it2.next());
            }
        }
        
        while(it1.hasNext()) ans.push_back(it1.next());
        while(it2.hasNext()) ans.push_back(it2.next());
        
        return ans;
    }
};