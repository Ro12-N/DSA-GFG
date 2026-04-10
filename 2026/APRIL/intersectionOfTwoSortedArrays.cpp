class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> ans;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++; j++;
                
                while(i < a.size() && a[i] == a[i-1]) i++;
                while(j < b.size() && b[j] == b[j-1]) j++;
            }
            else if(a[i] > b[j]){
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};
// Time Complexity: O(n + m) where n and m are the sizes of the two arrays
// Space Complexity: O(1) if we don't count the space used for the output array