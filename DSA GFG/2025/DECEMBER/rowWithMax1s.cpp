
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int i=0;
        int j=m-1;
        while(i<n &&j>=0){
            if(arr[i][j]==1){
                ans=i;
                j--;
            }else i++;
        }
        return ans;
    }
};

//time complexity: O(N + M) where N is the number of rows and M is the number of columns
//space complexity: O(1)