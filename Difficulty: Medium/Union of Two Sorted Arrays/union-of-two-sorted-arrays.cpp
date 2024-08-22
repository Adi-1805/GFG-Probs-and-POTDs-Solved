//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int> ans;
        int i1 = 0, i2 = 0;
        while(i1 < n and i2 < m){
            if(arr1[i1] < arr2[i2]) ans.insert(arr1[i1++]);
            else ans.insert(arr2[i2++]);
        }
        while(i1 < n){
            ans.insert(arr1[i1++]);
        }
        while(i2 < m){
            ans.insert(arr2[i2++]);
        }
        vector<int> v;
        for(auto it: ans){
            v.push_back(it);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends