class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dir = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };

    int i = 0, j = 0, d = 0;

    while (true) {
        if (mat[i][j] == 1) {
            d = (d + 1) % 4;
            mat[i][j] = 0;
        }

        int ni = i + dir[d][0];
        int nj = j + dir[d][1];

        if (ni < 0 || nj < 0 || ni >= n || nj >= m)
            return {i, j};

        i = ni;
        j = nj;
      }
      return {};
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(1)