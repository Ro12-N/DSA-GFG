class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> q;
        vector<int> ans;

        for (int j = 0; j < arr.size(); j++) {

            while (!q.empty() && arr[q.back()] < arr[j]) {
                q.pop_back();
            }
            q.push_back(j);

            while (!q.empty() && q.front() <= j - k) {
                q.pop_front();
            }

            if (j + 1 >= k) {
                ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }
};

// Time Complexity: O(N) where N is the length of arr
// Space Complexity: O(K) where K is the size of the subarray