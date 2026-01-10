class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mp;
        int i=0;
        for(int j=0;j<arr.size();j++){
            mp[arr[j]]++;
            if(j-i+1>k){
                if(--mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
            }
            if(j-i+1==k) ans.push_back(mp.size());
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(K)