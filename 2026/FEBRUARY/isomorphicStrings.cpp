class Solution {
public:
    bool areIsomorphic(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        vector<int> map1(256, -1);
        vector<int> map2(256, -1);

        for (int i = 0; i < s1.size(); i++) {
            unsigned char c1 = s1[i];
            unsigned char c2 = s2[i];

            if (map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                 map2[c2] = c1;
            }
            else if (map1[c1] != c2) {
                return false;
            }
        }
        return true;
    }
};
// Time Complexity: O(n) where n is the length of the input strings, due to the single pass through the strings
// Space Complexity: O(1) since the size of the mapping arrays is fixed at 256 for ASCII characters