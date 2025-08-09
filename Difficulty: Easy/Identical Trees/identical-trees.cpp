/* A binary tree node


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
    bool check(Node *r1, Node *r2){
        if(r1 == NULL and r2 == NULL) return 1;
        else if(r1 == NULL) return 0;
        else if(r2 == NULL) return 0;
        
        return (r1->data == r2-> data and check(r1->left, r2->left) and check(r1->right, r2->right));
    }
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        return check(r1, r2);
    }
};