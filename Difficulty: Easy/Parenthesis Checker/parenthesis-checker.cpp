
class Solution {
    unordered_map<char, int> bracket = { 
        {'(', 1}, 
        {')',-1}, 
        {'{', 2}, 
        {'}',-2}, 
        {'[', 3}, 
        {']',-3}
    };
public:
    bool isBalanced(string& k) {
        // code here
        stack<char> st;
        int i = 0;
        while(i < k.size()){
            char ch = k[i++];
            if(bracket[ch] > 0) st.push(ch);
            else if(!st.empty() and bracket[st.top()] + bracket[ch] == 0){
                st.pop();
            }
            else return false;
            
        }
        return (st.empty()) ;
    }
};