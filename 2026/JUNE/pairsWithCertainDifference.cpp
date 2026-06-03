class Solution {
  public:
int sumDiffPairs(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    int ans = 0;
    int i = arr.size() - 1;

    while (i > 0) {
        if (arr[i] - arr[i - 1] < k) {
            ans += arr[i] + arr[i - 1];
            i -= 2;  
        } else {
            i--;
        }
    }

    return ans;

    }
};
// TC: O(n log n) due to sorting
// SC: O(1)