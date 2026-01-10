class Solution {
  public:
    int minParentheses(string& s) {
        int o=0;
        int c=0;
        for(auto i:s){
            if(i=='(') o++;
            else {
                if(o) o--;
                else c++;
            }
        }
        return o+c;
    }
};