class Solution {
  public:
  vector<vector<int>>ans;
  unordered_set<int>st;
  void solve(vector<int>&nums,vector<int>&temp){
      if(temp.size()==nums.size()){
          ans.push_back(temp);
          return;
      }
      for(int i=0;i<nums.size();i++){
          if(!st.count(nums[i])){
              temp.push_back(nums[i]);
              st.insert(nums[i]);
              solve(nums,temp);
              st.erase(nums[i]);
              temp.pop_back();
          }
      }
  }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<int>temp;
        solve(arr,temp);
        return ans;
    }
};
// Time Complexity: O(N! * N) where N is the number of elements in the array
// Space Complexity: O(N) for recursive stack and O(N!) for storing all permutations