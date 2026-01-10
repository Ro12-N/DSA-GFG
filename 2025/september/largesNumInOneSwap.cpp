class Solution {
  public:
    string largestSwap(string &s) {
        vector<int> mp(10, 0);
    for (auto i : s) {
        mp[i - '0']++;
    }

    int idx = 9;
    int ch = -1;

    for (int i = 0; i < s.size(); i++) {
        while (idx >= 0 && mp[idx] == 0) idx--;

        if (s[i] - '0' < idx) {
            ch = s[i] - '0';
            s[i] = char(idx + '0'); 
            break;
        }
        mp[s[i] - '0']--;
    }

    if (ch == -1) return s; 

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] - '0' == idx) {
            s[i] = char(ch + '0'); 
            break;
        }
    }

    return s;
    }
};