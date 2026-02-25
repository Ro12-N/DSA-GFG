class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        unordered_map<int,int>mp;
        int p=0;
        int q=0;
        mp[0]=-1;
        int ans=0;
        for(int j=0;j<a1.size();j++){
            p+=a1[j];
            q+=a2[j];
            int diff=p-q;
            if(mp.count(diff)) ans=max(ans,j-mp[diff]);
            else mp[diff]=j;
        }
        return ans;
       
    }
};
// Time Complexity: O(n) where n is the size of the input arrays, due to the single pass through the arrays and hash map operations
// Space Complexity: O(n) in the worst case, if all prefix sum differences are unique