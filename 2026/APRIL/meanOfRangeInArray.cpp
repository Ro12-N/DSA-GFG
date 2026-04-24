class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int sum=0;
        vector<int>ans;
        for(auto i:arr){
            sum+=i;
            ans.push_back(sum);
        }
        vector<int>res;
        for(auto &i:queries){
            int s=i[0];
            int e=i[1];
            int val=ans[e]-((s==0)?0:ans[s-1]);
            res.push_back(val/(e-s+1));   
        }
        return res;
    }
};
// Time Complexity: O(n + q) where n is the size of the input array and q is the number of queries
// Space Complexity: O(n) for the prefix sum array and O(q) for the result