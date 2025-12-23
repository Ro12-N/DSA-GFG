class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(auto i:queries){
            int a=i[0];
            int b=i[1];
            int it1=lower_bound(arr.begin(),arr.end(),a)-arr.begin();
            int it2=upper_bound(arr.begin(),arr.end(),b)-arr.begin();
            ans.push_back(it2-it1);
        }
        return ans;
    }
};
//time complexity: O(N log N + Q log N) where N is the size of the array and Q is the number of queries
//space complexity: O(1) 