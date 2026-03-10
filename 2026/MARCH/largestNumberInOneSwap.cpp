class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.size();
        vector<int>l(10,-1);
        for(int i=0;i<n;i++){
            l[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++){
            for(int d=9;d>s[i]-'0';d--){
                if(l[d]>i){
                    swap(s[l[d]],s[i]);
                    return s;
                }
            }
        }
        return s;
    }
};
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(1) since we are using a fixed-size array to store the last occurrence of each digit.