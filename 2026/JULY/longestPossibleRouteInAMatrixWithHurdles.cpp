class Solution {
public:
int ans;
    void dfs(vector<vector<int>>& mat, int x, int y, int xd, int yd,int cnt) {
        if (x == xd && y == yd){
            ans=max(ans,cnt);
            return;
        }
           

        int n = mat.size();
        int m = mat[0].size();

        mat[x][y] = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny]) 
                 dfs(mat, nx, ny, xd, yd,cnt+1);
              
        }
      
        mat[x][y] = 1; 
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        if (!mat[xs][ys] || !mat[xd][yd])
            return -1;
         ans=-1;

         dfs(mat, xs, ys, xd, yd,0);
         return ans;
    }
};
// Time Complexity: O(4^(n*m)) in worst case
// Space Complexity: O(n*m) for recursion stack