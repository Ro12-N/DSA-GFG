class Solution {
public:
    int solve(vector<int>& arr, int k) {
        if (k == 0) return 0;

        unordered_map<int, int> mp;
        int ans = 0, i = 0;

        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;

            while (mp.size() > k) {
                if (--mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }

            ans += (j - i + 1);
        }
        return ans;   
    }

    int countAtMostK(vector<int>& arr, int k) {
        return solve(arr, k);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(K)