/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(root == NULL) return {};
        vector<int> ans;
        map<int, int> mp; // coordinate of vertical line, value of node
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
           
                auto curNode= q.front().first;
                int vline = q.front().second;
                q.pop();
                if(mp.find(vline) == mp.end()) mp[vline] = curNode->data;
                
                if(curNode->left) q.push({curNode->left, vline-1});
                if(curNode->right) q.push({curNode->right, vline+1});
                
            
        }
        for(auto it:mp) ans.push_back(it.second);
        
        return ans;
    }
};