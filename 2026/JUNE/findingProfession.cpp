class Solution {
public:
    string profession(int level, int pos) {
        int flips = __builtin_popcount(pos - 1);

        if (flips % 2 == 0)
            return "Engineer";
        return "Doctor";
    }
};
// Time Complexity: O(1) as we are using a constant amount of time to calculate the number of flips and determine the profession.
// Space Complexity: O(1) as we are using a constant amount of extra space to store the result.