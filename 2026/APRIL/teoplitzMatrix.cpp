class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]!=mat[i-1][j-1]) return false;
            }
        }
        return true;
    }
};
// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix
// Space Complexity: O(1) as we are using only a constant amount of extra space