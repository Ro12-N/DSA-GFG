class Solution {
public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        if ((n & (n - 1)) == 0)
            k /= 2;
        else
            k *= 2;

        string curr;

        for (char ch : s) {
            while (!curr.empty() && k > 0 && curr.back() > ch) {
                curr.pop_back();
                k--;
            }
            curr.push_back(ch);
        }

        while (!curr.empty() && k > 0) {
            curr.pop_back();
            k--;
        }
    
         if(curr.empty()) return "-1";
        return curr;
    }
};
// Time Complexity: O(N) where N is the length of the input string. We traverse the string once to construct the lexicographically smallest string.
// Space Complexity: O(N) in the worst case, if we end up keeping all characters