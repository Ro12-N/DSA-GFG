class Solution {
  public:
 bool check(int n, int m, int i, int j, pair<int, int> p) {
        if (i + p.first < 0 || j + p.second < 0 || i + p.first >= n || j + p.second >= m)
            return false;
        return true;
    }
    int numOfWays(int n, int m) {
        int tot = n * m;
        int res = 0;
        vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                                        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                res += (tot - 1);
                for (auto k : moves)
                    if (check(n, m, i, j, k))
                        res--;
            }
        return res;
    }
};
// Time Complexity: O(N*M) where N and M are the dimensions of the chessboard. We iterate through each cell of the board and check for valid knight moves.
// Space Complexity: O(1) as we are using a constant amount of extra space to store the moves and the result.