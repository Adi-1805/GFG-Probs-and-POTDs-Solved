/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    if(!root) return -1;
    int ans = -1;
    Node* temp = root;
    while(temp){
        int curr = temp->data;
        if(curr == input){
            return curr;
        }
        else if(curr >= input){
            temp = temp->left;
            ans = curr; 
        }else{
            temp = temp->right;
        }
    }
    return (ans == -1) ? -1: ans;
}