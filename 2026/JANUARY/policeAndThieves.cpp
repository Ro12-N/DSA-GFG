class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int i=0;
        int j=0;
        int n=arr.size();
        int ans=0;
        while(i<n &&j<n){
             while(i<n && arr[i]!='P') i++;
             while(j<n && arr[j]!='T')j++;
             if(i<n &&j<n){
                 if(abs(j-i)<=k){
                     ans++;
                     i++;
                     j++;
                 }else if(i<j) i++;
                 else j++;
             }
        }
        return ans;
    }
};
// Time Complexity: O(N) where N is the length of arr
// Space Complexity: O(1)