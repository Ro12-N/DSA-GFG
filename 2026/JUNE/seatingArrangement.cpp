class Solution {
public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                bool left  = (i == 0) || (seats[i - 1] == 0);
                bool right = (i == n - 1) || (seats[i + 1] == 0);

                if (left && right) {
                    seats[i] = 1;
                    k--;
                    if (k == 0) return true;
                }
            }
        }

        return k == 0;
    }
};
//  Time Complexity: O(N) where N is the number of seats. We traverse the seats array once.
// Space Complexity: O(1) as we are modifying the input array in place and using only a constant amount of extra space.