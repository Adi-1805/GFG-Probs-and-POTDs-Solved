class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        set<int> st;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                if(i == n/i) st.insert(i);
                else {
                    st.insert(i);
                    st.insert(n/i);
                }
            }
        }
        for(auto it = st.begin(); it != st.end(); it++){
            cout << *it << " ";
        }
        
    }
};