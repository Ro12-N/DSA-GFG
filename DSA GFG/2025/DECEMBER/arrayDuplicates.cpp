class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int>ans;
        unordered_set<int>st;
        for(auto i:arr){
            if(st.count(i)) ans.push_back(i);
            st.insert(i);
        }
        return ans;
    }
};