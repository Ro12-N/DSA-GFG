class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n=s1.size();
        int m=s2.size();
        int sidx=-1;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            int j=0;
            int k=i;
            if(s1[k]==s2[j]){
                while(k<n &&j<m){
                    if(s1[k]==s2[j]) j++;
                    k++;
                }
            }
            if(j==m){
                if(len>k-i){
                    len=k-i;
                    sidx=i;
                }
            }
        }
        
        
        if(sidx==-1) return "";
        return s1.substr(sidx,len);
    }
};

// Time Complexity: O(N*M) where N is the length of s1 and M is the length of s2
// Space Complexity: O(1)