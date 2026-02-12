class Solution {
  public:
  
  bool solve(int m, vector<int>& arr, int k) {
      long long ans = 0;
      for (auto i : arr) {
          ans += i / m;
          if (i % m) ans++;
      }
      return ans <= k;
  }

  int kokoEat(vector<int>& arr, int k) {
      int s = 1;
      int e = *max_element(arr.begin(), arr.end());
      int ans = e;

      while (s <= e) {
          int mid = s + (e - s) / 2;
          if (solve(mid, arr, k)) {
              ans = mid;
              e = mid - 1;
          } else {
              s = mid + 1;
          }
      }
      return ans;
  }
};

// Time Complexity: O(N log M) where N is the size of the input array and M is the maximum element in the array
// Space Complexity: O(1)
