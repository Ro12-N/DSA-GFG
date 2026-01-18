class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char>st;
        for(auto i:s){
           if(i==')'){
               bool f=true;
               while(!st.empty()&& st.top()!='('){
                   char ch=st.top();
                   st.pop();
                   if(ch=='+'||ch=='-'||ch=='*'||ch=='/') f=false;
                   
               }
               st.pop();
               if(f) return true;
               
           }else st.push(i);
        }
        return false;
    }
};
// Time Complexity: O(N) where N is the length of string s
// Space Complexity: O(N)