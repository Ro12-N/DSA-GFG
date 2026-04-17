class Solution {
  public:
    int myAtoi(string &s) {
        // code here
         int n=s.length();
      int sign=+1;
      long num=0;
      int i=0;

      while(i<n&&s[i]==' '){
        i++;
      }
      if(i<n&&s[i]=='-') sign=-1;
      if(i<n&&(s[i]=='-'||s[i]=='+')) i++;

      while(i<n&&isdigit(s[i])){
        num=num*10+(s[i]-'0');
        if(sign==-1 && -num<INT_MIN) return INT_MIN;
        if(sign==+1 && num>INT_MAX) return INT_MAX;
        i++;
      }
      return (sign*num);
    }
};
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1) as we are using only a constant amount of extra space