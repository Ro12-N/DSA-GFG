class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
       vector<int>freq(26,0);
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            int maxi=*max_element(freq.begin(),freq.end());
            while((j-i+1)-maxi >k){
                freq[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the length of the input string s, as we traverse the string once with two pointers.
// Space Complexity: O(1) since the frequency array will always have a fixed size of 26 for the uppercase English letters.