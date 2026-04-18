class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>vec(26,0);
        for(auto i:s){
            vec[i-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(vec[i]!=0 && vec[i]%2==1) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1) as we are using only a constant amount of extra space