/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/
class Solution {
    void findTarget(Node* root, int target, Node*& temp){
        if(root == NULL) return ;
        if(root->data == target){
            temp = root; return;
        }
        findTarget(root->left, target, temp);
        findTarget(root->right, target, temp);
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        // Mark parent children nodes
        unordered_map<Node*, Node*> parent_child;
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr->left){
                parent_child[curr->left] = curr; q.push(curr->left);
            }
            if(curr->right){
                parent_child[curr->right] = curr; q.push(curr->right);
            }
        }
        // Find start node address
        Node* startNode = NULL; findTarget(root, target, startNode);

        // Start traversing in all direction from the startNode
        int cur_dist = 0; 
        unordered_map<Node*, int> vis; 
        q.push(startNode); vis[startNode] = 1;
        while(!q.empty()){
            int n = q.size(); cur_dist++;
            while(n--){
                auto curr = q.front();
                q.pop();
                if(curr->left and !vis[curr->left]){
                    vis[curr->left] = 1; q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    vis[curr->right] = 1; q.push(curr->right);
                }
                if(parent_child.find(curr) != parent_child.end() and !vis[parent_child[curr]]){
                    vis[parent_child[curr]] = 1; q.push(parent_child[curr]);
                }
            }
        }
        return --cur_dist; // -- because we're counting the start node too
        
    }
};