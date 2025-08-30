class Solution {
    vector<int> KahnAlgo(int V, vector<vector<int>>& adj){
        vector<int> topoSort;
        queue<int> q; 
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int verti: adj[i]) indegree[verti]++;
        }
        
        for(int v = 0; v < V; v++) if(indegree[v] == 0) q.push(v);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(int next: adj[node]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        return topoSort;
    }
  public:
    string findOrder(vector<string> &words) {
        set<char> letters;
        for(const auto& word : words) {
            for(char c : word) {
                letters.insert(c);
            }
        }
        int V = letters.size();
        vector<vector<int>> adjList(26);
        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i], s2 = words[i+1];
            bool difference_found = false;
            for(int ptr = 0; ptr < min(s1.size(), s2.size()); ptr++){
                if(s1[ptr] != s2[ptr]){
                    adjList[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    difference_found = true;
                    break; 
                }
            }
            // Check for invalid order, e.g., ["abc", "ab"]
            if (!difference_found && s1.size() > s2.size()) {
                return "";
            }
        }
        
        vector<int> alphabet = KahnAlgo(26, adjList);
        
        string order = "";
        for(int val: alphabet){
            if (letters.count(char(val + 'a'))) {
                order += char(val + 'a');
            }
        }
        
        // Last check is whether the final_order contains all the letters or not, if not return "".
        return (order.size() == letters.size()) ? order : "";
    }
};
