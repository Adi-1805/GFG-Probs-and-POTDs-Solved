class Solution {
    void helper(vector<string>& ans, string s, string& temp, vector<bool>& vis){
        if(temp.size() == s.size()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(vis[i] || (i > 0 and s[i] == s[i-1] and vis[i-1] == 0)) continue;
            else{
                temp.push_back(s[i]);
                vis[i] = 1;
                helper(ans, s, temp, vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
        
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        sort(s.begin(), s.end());
        vector<string> ans;
        string temp = "";
        vector<bool> vis(s.size(), 0);
        helper(ans, s, temp, vis);
        return ans;
    }
};
