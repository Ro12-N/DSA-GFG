class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st;
        for(auto i:a) st.insert(i);
        for(auto i:b) st.insert(i);
        return vector<int>(st.begin(),st.end());
    }
};
//Time Complexity: O(n + m) where n and m are the sizes of the two input arrays, due to the single pass through both arrays and the hash set operations
// Space Complexity: O(n + m) in the worst case, if all elements in both