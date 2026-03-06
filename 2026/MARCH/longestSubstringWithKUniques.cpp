class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
       vector<int>mp(26,0);
        int i=0;
        int n=s.size();
        int ans=-1;
        int dis=0;
        for(int j=0;j<n;j++){
          int idx=s[j]-'a';
          if(mp[idx]==0) dis++;
          mp[idx]++;
          while(dis>k){
             int idx=s[i]-'a';
             if(--mp[idx]==0) dis--;
             i++;
          }
          if(dis==k) ans=max(ans,j-i+1);
        }
        return ans;
    }
};

//Time Complexity: O(N) where N is the size of the input string.
//Space Complexity: O(1) as we are using only constant extra space.