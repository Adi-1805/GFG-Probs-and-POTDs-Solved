/*  Structure of a Binary Tree

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
    int maxWidth(Node* root) {
        // code here
        int maxWidth = 0;
        queue<pair<Node*, int>> q; // {node, index}
        q.push({root, 0});
        
        while(!q.empty()){
            int n = q.size();
            int minIndex = q.front().second;
            
            maxWidth = std::max(maxWidth, n);
            
            for(int i = 0; i < n; i++){
                auto node = q.front().first;
                auto index = q.front().second-minIndex;
                q.pop();
                
                Node* left = node->left;
                Node* right = node->right;
                
                if(left) q.push({left, 2*index+1});
                if(right) q.push({right, 2*index+2});
            }
            
        }
        
        return maxWidth;
    }
};