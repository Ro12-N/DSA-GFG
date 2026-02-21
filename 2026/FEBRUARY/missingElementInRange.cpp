class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int>st(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=low;i<=high;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
// Time Complexity: O(n) due to the creation of the unordered set and the loop to find missing elements
// Space Complexity: O(n) due to the unordered set storing the elements of the array and