class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n=a.size();
        int m=b.size();
        int i=0;
        int j=0;
        int ans=0;
        int s1=0,s2=0;
        while(i<n &&j<m){
            if(a[i]==b[j]){
                ans+=max(s1,s2)+a[i];
                i++;
                j++;
                s1=0;
                s2=0;
            }else if(a[i]<b[j]){
                s1+=a[i++];
            }else{
                s2+=b[j++];
            }
        }
        while(i<n) s1+=a[i++];
        while(j<m) s2+=b[j++];
        return ans+max(s1,s2);
    }
};
// Time Complexity: O(n+m)
// Space Complexity: O(1)