class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int max_len = INT_MIN;
        unordered_map<char, int> char_freq;
        int i = 0, j = 0;
        while(j<n){
            char_freq[s[j]]++;
            if(char_freq.size() == k){
                max_len = max(max_len, j-i+1);
            }
            while(char_freq.size() > k){
                char_freq[s[i]]--;
                if(char_freq[s[i]] == 0) char_freq.erase(s[i]);
                i++;
            }
            j++;
        }
        return (max_len == INT_MIN) ? -1 : max_len;
    }
};