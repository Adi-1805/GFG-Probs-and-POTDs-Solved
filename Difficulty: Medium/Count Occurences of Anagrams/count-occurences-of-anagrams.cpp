// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int count = 0;
        unordered_map<char, int> mp1, mp2;
        for(char ch: pat) mp1[ch]++;
        int i = 0, j = 0;
        for(; j < txt.size(); j++){
            mp2[txt[j]]++;
            if(j-i+1 == pat.size()){
                if(mp1 == mp2) count++;
                mp2[txt[i]]--;
                if(mp2[txt[i]] == 0) mp2.erase(txt[i]);
                i++;
            }
        }
        return count;
    }
};