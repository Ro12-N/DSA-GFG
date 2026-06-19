class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int cnt=0;

        for (int i = 0; i < n; i++) {
            int seen = 0;
            for (int j = 0; j < m; j++) {
                if(mat[i][j]==0)
                cnt += seen;
                seen |= mat[i][j];
            }
        }

 
        for (int i = 0; i < n; i++) {
            int seen = 0;
            for (int j = m - 1; j >= 0; j--) {
                if(mat[i][j]==0)
                cnt += seen;
                seen |= mat[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            int seen = 0;
            for (int i = 0; i < n; i++) {
                if(mat[i][j]==0)
               cnt+=  seen;
                seen |= mat[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            int seen = 0;
            for (int i = n - 1; i >= 0; i--) {
                if(mat[i][j]==0)
                cnt+=  seen;
                seen |= mat[i][j];
            }
        }

       
        return cnt;
    }
};
// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity: O(1) as we are using only a constant amount of extra space