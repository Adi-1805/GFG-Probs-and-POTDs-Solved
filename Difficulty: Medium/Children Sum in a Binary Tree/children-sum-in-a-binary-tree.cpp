/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool checkSum(Node* root){
        if(root == NULL) return 1;
        if(!root->left and !root->right) return 1;
        
        int childSum = 0;
        if(root->left) childSum += root->left->data;
        if(root->right) childSum += root->right->data;
        
        return (childSum == root->data and checkSum(root->left) and checkSum(root->right) );
        
    }
    int isSumProperty(Node *root) {
        // Add your code here
        return checkSum(root);
    }
};