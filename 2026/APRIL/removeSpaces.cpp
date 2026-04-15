class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans="";
        for(auto i:s){
            if(i!=' ') ans+=i;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(n) as we are using an extra string to store the result