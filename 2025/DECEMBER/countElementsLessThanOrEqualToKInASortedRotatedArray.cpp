class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        
        if (arr[0] <= arr[n-1]) {
            return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        }

        int i = 1;
        while (i < n && arr[i-1] <= arr[i]) i++;

        int cnt = upper_bound(arr.begin(), arr.begin() + i, x) - arr.begin();

        cnt += upper_bound(arr.begin() + i, arr.end(), x) - (arr.begin() + i);

        return cnt;
    }
};

// Time Complexity: O(N) in worst case for finding pivot + O(log N) for upper_bound
// Space Complexity: O(1)