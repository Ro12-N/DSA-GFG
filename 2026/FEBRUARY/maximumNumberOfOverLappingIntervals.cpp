class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
       vector<int>s,e;
       for(auto i:arr){
           s.push_back(i[0]);
           e.push_back(i[1]);
       }
       sort(s.begin(),s.end());
       sort(e.begin(),e.end());
       int i=0;
       int j=0;
       int ans=0;
       int maxi=0;
       while(i<s.size() &&j<e.size()){
           if(s[i]<=e[j]){
               ans++;
               maxi=max(maxi,ans);
               i++;
           }else{
               ans--;
               j++;
           }
       }
       
       
       return maxi;
    }
};

// Time Complexity: O(n log n) due to sorting the start and end times
// Space Complexity: O(n) 