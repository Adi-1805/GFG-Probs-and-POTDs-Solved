class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> st;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            st.push(element);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            q.push(element);
        }
        
    }
};