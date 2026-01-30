class Solution {
public:
    string firstNonRepeating(string &s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for(char ch : s) {
            freq[ch - 'a']++;
            q.push(ch);

            while(!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if(q.empty()) ans += '#';
            else ans += q.front();
        }

        return ans;
    }
};

// Time Complexity: O(N) where N is the length of the string
// Space Complexity: O(1) since the frequency array size is constant (26 for lowercase