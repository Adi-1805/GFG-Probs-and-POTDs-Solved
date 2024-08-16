//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         // l, r and m all are indices
        int l_sz = m - l + 1; // size of arr 1
        int L[l_sz + 1];        // +1 becuz last element of both the arrays would be INT_MAX
        int r_sz = r - m;
        int R[r_sz + 1]; // +1 becuz last element of both the arrays would be INT_MAX
        // making the two arrays by copying the elements
        for(int i=0; i<l_sz; i++){
            L[i] = arr[i + l];
        }
        for(int i=0; i<r_sz; i++){
            R[i] = arr[i + m + 1]; // "m+1" is the first element of this array
        }
        L[l_sz] = R[r_sz] = INT_MAX;
        /* The last element of both the arrays will be int_max because we want ki end tk comparison ho and kisi ek array ek khatm hone pr while loops na lagane pde (like in the traditional method) */
        int l_i = 0;
        int r_i = 0;
        for(int i=l; i<r + 1; i++){
            if (L[l_i] <= R[r_i]){
                arr[i] = L[l_i++];
            }
            else{
                arr[i] = R[r_i++];
            }
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l == r)
        return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);     // firstly, the first half of the array is completely sorted
        mergeSort(arr, mid + 1, r); // secondly, the second half is sorted
        merge(arr, l, mid, r);      // both the sorted halves are merged
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends