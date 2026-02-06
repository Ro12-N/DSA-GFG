class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int ans=0;
        int i=0;
        int n=arr.size();
        for(int j=0;j<n;j++){
            if(arr[j]==0){
                k--;
            }
            while(k<0){
                if(arr[i]==0){
                   k++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};

// Time Complexity: O(N) where N is the size of arr
// Space Complexity: O(1)