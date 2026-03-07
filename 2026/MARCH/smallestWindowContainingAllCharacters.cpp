class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        if(p.size()>s.size()) return "";
        int n=s.size();
        int start=-1;
        int minisize=INT_MAX;
        int i=0;
        int j=0;
        int cnt=p.size();
        vector<int>mp(26,0);
        for(auto i:p){
            mp[i-'a']++;
        }
        while(j<n){
            int idx=s[j]-'a';
            if(mp[idx]>0) cnt--;
            mp[idx]--;
            while(cnt==0){
                int curr=j-i+1;
                if(minisize>curr){
                    minisize=curr;
                    start=i;
                }
                mp[s[i]-'a']++;
                if(mp[s[i]-'a']>0) cnt++;
                i++;
            }
            j++;
            
        }
        return (minisize==INT_MAX)?"":s.substr(start,minisize);
    }
};
//Time Complexity: O(N) where N is the size of the input string.
//Space Complexity: O(1) as we are using only constant extra space.