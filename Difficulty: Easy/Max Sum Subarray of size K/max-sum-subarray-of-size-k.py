class Solution:
    def maxSubarraySum(self, arr, k):
        # code here 
        n = len(arr)
        i = 0
        j = 0
        cursum = 0
        max_sum = 0
        while(j < n):
            # cursum = sum of element from i to j
            cursum = cursum + arr[j]
            if(j -i+1 == k):
                max_sum = max(cursum, max_sum)
                # subtracting ith element and moving the window forward
                cursum = cursum - arr[i]
                j += 1
                i += 1
            else:
                j += 1
        return max_sum
                
                