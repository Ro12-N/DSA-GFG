class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int maxi=0;
        for(auto i:arr){
             maxi=max(maxi,i[1]);
            if(!ans.empty() && ans.back()[1]>=i[0]){
                ans.back()[1]=maxi;
            }else{
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
//time complexity: O(NlogN) + O(N)
//space complexity: O(1)