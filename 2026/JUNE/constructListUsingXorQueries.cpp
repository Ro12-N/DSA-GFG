class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int n=queries.size();
        int xr=0;
        vector<int>ans;
       for(int i=n-1;i>=0;i--){
           if(queries[i][0]==1){
               xr^=queries[i][1];
           }else{
               ans.push_back(xr^queries[i][1]);
           }
       }
       ans.push_back(xr);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) for the answer vector