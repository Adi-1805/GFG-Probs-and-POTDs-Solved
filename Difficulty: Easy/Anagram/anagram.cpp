class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(char ch: s1){
            hash1[ch-'a']++;
        }
        for(char ch: s2){
            hash2[ch-'a']++;
        }
        
        return (hash1 == hash2);
    }
};