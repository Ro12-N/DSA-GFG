class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        unordered_map<int,vector<int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<=(m-1)+(n-1);i++){
            for(auto j:mp[i]) ans.push_back(j);
        }
        return ans;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)