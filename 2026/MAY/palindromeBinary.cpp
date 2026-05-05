class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        string s = "";
        
        while(N){
            char ch = (N % 2) + '0';
            s+=ch;  
            N /= 2;
        }
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};