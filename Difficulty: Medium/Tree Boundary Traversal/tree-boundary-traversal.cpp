/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    vector<int> ans;
    void leftBoundary(Node* root) {
        if (!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if (root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }

    void rightBoundary(Node* root) {
        if (!root || (!root->left && !root->right)) return;
        if (root->right) rightBoundary(root->right);
        else rightBoundary(root->left);
        ans.push_back(root->data); // Add after child call for reverse order
    }

    void leaves(Node* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        leaves(root->left);
        leaves(root->right);
    }

public:
    vector<int> boundaryTraversal(Node *root) {
        if (!root) return ans;

        ans.push_back(root->data);

        // Add left boundary (excluding root and leaves)
        leftBoundary(root->left);

        // Add leaves (left and right subtrees, excluding root if it's a leaf)
        leaves(root->left);  // Leaves in left subtree
        leaves(root->right); // Leaves in right subtree

        // Add right boundary (excluding root and leaves)
        rightBoundary(root->right);

        return ans;
    }
};