class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        auto it=lower_bound(arr.begin(),arr.end(),k);
        return it-arr.begin();
    }
};

//time complexity: O(logN)
//space complexity: O(1)