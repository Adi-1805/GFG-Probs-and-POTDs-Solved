class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int n = s.size();
        unordered_map<char, int> char_freq;
        int i = 0, j = 0;
        int max_len = 1;
        while(j < n){
            char_freq[s[j]]++;
            int cur_len = j -i +1;
            // checking the equality case
            if(char_freq.size() == cur_len) max_len = max(max_len, cur_len);
            // reducing 
            // NOTE: using formula instead of cur_len becuase i is changing here
            while(char_freq.size() < j -i +1){
                char_freq[s[i]]--; 
                if(char_freq[s[i]] == 0) char_freq.erase(s[i]);
                i++;
            }
            // routine increment
            j++;
        }
        return max_len;
    }
};