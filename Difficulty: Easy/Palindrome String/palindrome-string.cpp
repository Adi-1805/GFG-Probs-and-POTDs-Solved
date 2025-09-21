class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] == s[r]){
                l++; r--;
            }
            else return false;
        }
        return true;
    }
};