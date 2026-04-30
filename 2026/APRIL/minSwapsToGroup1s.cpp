class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int num1 = 0;
        for(auto it : arr)
        {
             if(it==1)
             {
                 num1++;
             }
        }
        
        if(num1==0)
         return -1;
         
        int ans = n;
        vector<int> prefix(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0 && arr[i]==0)
            prefix[i] = 1;
            else {
            prefix[i] = prefix[i-1];
            if(arr[i]==0)
            prefix[i] += 1;
            }            
        }
        
        
        int j=num1-1;
        for(j;j<n;j++)
        {
             int last = j - num1;
             if(last>=0)
             ans = min(ans,prefix[j]-prefix[last]);
             else
             ans = min(ans,prefix[j]);
        }
        
        
        return ans;
    }
};
// Time Complexity: O(n) where n is the length of the input array arr, as we traverse the array a few times with linear complexity.
// Space Complexity: O(n) due to the prefix array used to store the cumulative count of zeros up to each index.