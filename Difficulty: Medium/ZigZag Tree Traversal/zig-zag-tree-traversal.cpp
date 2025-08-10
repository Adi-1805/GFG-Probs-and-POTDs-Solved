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

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        if(root == NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<int> final;
        bool direction = 0; // 0 -> LtoR and 1 -> RtoL
        
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            while(n--){
                auto node = q.front();
                q.pop();
                lvl.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(direction) reverse(lvl.begin(), lvl.end());
            
            final.insert(final.end(), lvl.begin(), lvl.end());
            direction = !direction;
        }
        return final;
    }
};