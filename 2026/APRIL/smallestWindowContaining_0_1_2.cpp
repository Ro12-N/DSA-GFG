class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int ans=INT_MAX;
        unordered_map<char,int>mp;
        int i=0;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            while(mp.size()==3){
                ans=min(ans,j-i+1);
                if(--mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// Time Complexity: O(n) where n is the length of the input string s, as we traverse the string once with two pointers.
// Space Complexity: O(1) since the unordered_map will at most contain three key-value pairs for the characters '0', '1', and '2'.