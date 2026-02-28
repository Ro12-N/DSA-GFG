class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));

        // Build prefix sum
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefix[i][j] = mat[i][j];

                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        int count = 0;

    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int len = 0; i+len < n && j+len < m; len++){

                    int r = i + len;
                    int c = j + len;

                    int total = prefix[r][c];

                    if(i > 0) total -= prefix[i-1][c];
                    if(j > 0) total -= prefix[r][j-1];
                    if(i > 0 && j > 0) total += prefix[i-1][j-1];

                    if(total == x)
                        count++;
                }
            }
        }

        return count;
    }
};
// Time Complexity: O(n^3) where n is the size of the matrix, due to the three nested loops for counting squares
// Space Complexity: O(n*m) for the prefix sum matrix, where n and m are