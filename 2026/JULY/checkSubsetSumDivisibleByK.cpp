class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(vector<int>& arr, int k, int idx, int sum, bool taken) {
        if (idx == n)
            return taken && sum == 0;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool take = solve(arr, k, idx + 1, (sum + arr[idx]) % k, true);
        bool skip = solve(arr, k, idx + 1, sum, taken);

        return dp[idx][sum] = take || skip;
    }

    bool divisibleByK(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, vector<int>(k, -1));
        return solve(arr, k, 0, 0, false);
    }
};
// TC: O(N*K)
// SC: O(N*K)