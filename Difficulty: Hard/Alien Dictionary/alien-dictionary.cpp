#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> topo;
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true;
        for (int next : adj[node]) {
            if (!vis[next]) {
                if (dfs(next, adj, vis, pathVis)) {
                    return true; // Cycle detected
                }
            } else if (pathVis[next]) {
                return true; // Cycle detected
            }
        }
        pathVis[node] = false;
        topo.push_back(node);
        return false;
    }

public:
    string findOrder(vector<string>& words) {
        if (words.empty()) return "";

        // Initialize adjacency list for 26 letters
        vector<vector<int>> adj(26);

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            // Handle cases like ["abc", "ab"] where the first word is longer
            if (!found && s1.size() > s2.size()) {
                return ""; // Invalid order
            }
        }

        // Initialize visited arrays
        vector<bool> vis(26, false);
        vector<bool> pathVis(26, false);
        topo.clear();

        // Perform DFS for all unvisited nodes present in the words
        vector<bool> present(26, false);
        for (string word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (present[i] && !vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return ""; // Cycle detected
                }
            }
        }

        // Reverse to get topological order
        reverse(topo.begin(), topo.end());

        // Build the result string
        string ans;
        for (int node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};