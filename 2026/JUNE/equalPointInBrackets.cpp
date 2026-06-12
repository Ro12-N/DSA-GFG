class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int c=0;
        for(auto i:s){
            if(i==')') c++;
        }
        int o=0;
        for(int i=0;i<s.size();i++){
            if(o==c) return i;
            if(s[i]=='(')o++;
            else c--;
        }
        return (int)s.size();
    }
};
// TC : O(N)
// SC : O(1)