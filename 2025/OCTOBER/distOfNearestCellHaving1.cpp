class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1; 
                }
            }
        }

    
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                for(auto &d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == -1) {
                        grid[ni][nj] = level + 1; 
                        q.push({ni, nj});
                    }
                }
            }
            level++; 
        }

        return grid;
    }
};

// TC = O(n × m)
// SC = O(n × m)