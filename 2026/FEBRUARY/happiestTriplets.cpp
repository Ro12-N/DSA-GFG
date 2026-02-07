class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        vector<int>ans;
        int diff=INT_MAX;
        int sum=INT_MAX;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i=0;
        int j=0;
        int k=0;
        while(i<a.size()&&j<b.size()&&k<c.size()){
            int x=a[i];
            int y=b[j];
            int z=c[k];
            int currsum=x+y+z;
            int maxi=max({x,y,z});
            int mini=min({x,y,z});
            if(diff>(maxi-mini)||(diff==(maxi-mini) && currsum<sum )){
                ans={x,y,z};
                diff=maxi-mini;
                sum=currsum;
            }
            
            if(mini==x) i++;
            else if(mini==y) j++;
            else k++;
        }
        
        
        
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};
// Time Complexity: O(NlogN) where N is the size of the largest array among a, b and c
// Space Complexity: O(1)