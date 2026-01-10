class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<long long> dp(n);  
        int ans = 0;

        for(int i = 0; i < n; i++) {
            dp[i] = arr[i]; /
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = max(ans, (int)dp[i]);
        }
        return ans;
    }
};
