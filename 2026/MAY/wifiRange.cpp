class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n=s.size();
        int curr=0;
        for(auto i:s){
            if(i=='1') curr=x;
            else curr--;
            if(abs(curr)>x) return false;
        }
        return curr>=0;
    }
};
// TC : o(n)
// SC : o(1)