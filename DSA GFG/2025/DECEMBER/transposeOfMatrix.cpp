class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        return mat;
    }
};
// Time Complexity: O(N*M)
// Space Complexity: O(1)