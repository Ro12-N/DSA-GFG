class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> ans;

        for (int x : arr) {
            bool inserted = false;

            while (!ans.empty() && ans.back() * x < 0) { 
                
                if (abs(ans.back()) < abs(x)) {
                    ans.pop_back(); 
                    continue;   
                } 
                else if (abs(ans.back()) == abs(x)) {
                    ans.pop_back(); 
                    inserted = true;
                    break;
                } 
                else {
                    inserted = true; 
                    break;
                }
            }

            if (!inserted) ans.push_back(x);
        }

        return ans;
    }
};
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(n) in the worst case when no pairs are reduced and all elements are stored in the answer vector.