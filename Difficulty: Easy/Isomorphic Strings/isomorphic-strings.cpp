class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for(int i = 0; i < n; i++){
            if(mp1.find(s1[i]) == mp1.end() and mp2.find(s2[i]) == mp2.end()){
                mp1[s1[i]] = s2[i];
                mp2[s2[i]] = s1[i];
            }
            else if(mp1.find(s1[i]) == mp1.end() and mp2.find(s2[i]) != mp2.end()){
                if(mp2[s2[i]] != s1[i]) return false;
            }
            else if(mp1.find(s1[i]) != mp1.end() and mp2.find(s2[i]) == mp2.end()){
                if(mp1[s1[i]] != s2[i]) return false;
            }
            else{
                if(mp1[s1[i]] != s2[i] or mp2[s2[i]] != s1[i]) return false;
            }
        }
        return true;
    }
};