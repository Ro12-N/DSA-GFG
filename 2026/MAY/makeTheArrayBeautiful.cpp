class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        for(auto i:arr){
            if(!ans.empty() && ((ans.back()<0 && i>=0)||(ans.back()>=0 && i<0))){
                ans.pop_back();
       
            }else ans.push_back(i);
        }
        return ans;
    }
};
// TC : O(N)
// SC : O(N)