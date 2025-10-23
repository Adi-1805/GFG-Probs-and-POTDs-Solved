class Solution {
    void solve(int ind, string &answer, string &s, int k){
        if(ind == s.size() or k == 0) {
            answer = max(answer, s);
            return ;
        }
    
        for(int i = ind; i < s.size(); i++){
            if(s[i] > s[ind]) {
                swap(s[i], s[ind]);
                solve(ind+1, answer, s, k-1);
                swap(s[ind], s[i]);
            } else {
                solve(ind+1, answer, s, k);
            }
        }
        
    }
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string answer = s;
        solve(0, answer, s, k);
        return answer;
    }
};