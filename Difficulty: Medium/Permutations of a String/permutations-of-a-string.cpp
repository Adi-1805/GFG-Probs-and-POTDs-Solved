class Solution {
    void permute(string in, string out, vector<string>& result){
        if(in.size() == 0){
            result.push_back(out);
        }
        
        unordered_set<char> used;
        for(int i = 0; i < in.size(); i++){
            
            if(used.count(in[i])) continue;
            
            used.insert(in[i]);
            string newIn = in.substr(0, i) + in.substr(i+1, in.size()-i-1); 
            string newOut = out + in[i];
            permute(newIn, newOut, result);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        string input = s;
        string output = "";
        vector<string> result;
        permute(input, output, result);
        return result;
    }
};
