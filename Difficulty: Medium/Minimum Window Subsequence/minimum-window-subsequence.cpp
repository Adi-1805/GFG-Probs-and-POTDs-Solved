class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        int min_len = INT_MAX;
        string res = "";
        
        int i = 0; // Pointer for s1
        int j = 0; // Pointer for s2
        
        // Iterate through s1 to find the end of the subsequence
        while (i < n) {
            if (s1[i] == s2[j]) {
                j++;
            }
            
            // If j reaches m, we found all characters of s2 in s1 (in order)
            if (j == m) {
                // Step 1: Initialize end of window
                int end = i; 
                j--; // Point back to the last character of s2
                
                // Step 2: OPTIMIZE START (Backtrack)
                // Go backwards from 'end' to find the closest starting character
                while (j >= 0) {
                    if (s1[i] == s2[j]) {
                        j--;
                    }
                    i--;
                }
                // After loop, 'i' is one step BEFORE the valid start. 
                // So the real start is i+1.
                i++; 
                j++; // Reset j to 0 for the next potential search
                
                // Step 3: Check if this is the shortest window found so far
                int current_len = end - i + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    res = s1.substr(i, current_len);
                }
            }
            i++;
        }
        
        return res;
    }
};