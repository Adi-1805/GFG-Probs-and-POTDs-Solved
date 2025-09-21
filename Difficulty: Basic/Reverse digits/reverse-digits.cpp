class Solution {
  public:
    int string_to_int(string s){
        stringstream ss(s);
        int num = 0;
        ss >> num;
        return num;
    }
    int reverseDigits(int n) {
        // Code here
        string num = to_string(n);
        reverse(num.begin(), num.end());
        return string_to_int(num);
    }
};