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
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        vector<int> ans;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            while(n--){
                auto cur = q.front();
                q.pop();
                lvl.push_back(cur->data);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(lvl[0]);
        }
        return ans;
    }
};