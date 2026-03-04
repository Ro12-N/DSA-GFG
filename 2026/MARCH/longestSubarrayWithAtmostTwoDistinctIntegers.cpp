class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int ans=0;
        int i=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        int d=0;
        for(int j=0;j<n;j++){
            mp[arr[j]]++;
            if(mp[arr[j]]==1) d++;
            while(d>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0) d--;
                i++;
            }
            ans=max(ans,j-i+1);
            
        }
        return ans;
    }
};
//Time Complexity: O(N) where N is the size of the input array.
//Space Complexity: O(N) where N is the size of the input array.