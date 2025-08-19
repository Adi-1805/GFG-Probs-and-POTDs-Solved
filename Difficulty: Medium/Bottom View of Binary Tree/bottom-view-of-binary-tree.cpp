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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        if(!root) return {};
        map<int, int> mp; // {vertical, node}
        queue<pair<int, Node*>> q; // {vertical, node}
        q.push({0, root});
        while(!q.empty()){
            auto vertical = q.front().first;
            auto node = q.front().second;
            q.pop();
            
            mp[vertical] = node->data;
            if(node->left) q.push({vertical-1, node->left});
            if(node->right) q.push({vertical+1, node->right});
        }
        
        vector<int> ans;
        for(auto it: mp) ans.push_back(it.second);
        return ans;
    }
};