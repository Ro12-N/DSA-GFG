class Solution {
public:
    int solve(vector<vector<int>>& mat, int m, int n, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) return 0;
        
        if (i == n - 1 && j == m - 1)
            return (k == mat[i][j]) ? 1 : 0;
        
        if (dp[i][j][k] != -1) return dp[i][j][k];
        
        int remaining = k - mat[i][j];
        if (remaining < 0) return 0;
        
        int down = solve(mat, m, n, i + 1, j, remaining, dp);
        int right = solve(mat, m, n, i, j + 1, remaining, dp);
        
        return dp[i][j][k] = down + right;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(mat, m, n, 0, 0, k, dp);
    }
};
