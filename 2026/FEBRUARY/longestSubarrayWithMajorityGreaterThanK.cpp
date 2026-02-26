class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int cnt=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>k) cnt++;
            else cnt--;
            if(cnt>0) ans=max(ans,i+1);
            if(mp.count(cnt-1)) ans=max(ans,i-mp[cnt-1]);
            if(!mp.count(cnt)) mp[cnt]=i;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the size of the input array, due to the single pass through the array and hash map operations
// Space Complexity: O(n) in the worst case, if all prefix sum differences are unique