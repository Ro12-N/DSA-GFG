class Solution {
  public:
    virtual string URLify(string &s){
      string rep="%20";
      string ans="";
      
      int sn=s.size();
      for(int i=0; i<sn; i++){
        if(s[i]==' ') ans+=rep;
        else ans+=s[i];
      }
      
      return ans;
    }
};
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(n) as we are using an extra string to store the result