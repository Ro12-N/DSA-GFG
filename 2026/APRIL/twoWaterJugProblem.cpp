class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int solve(int from, int to, int d) {
        int fromJug = from;
        int toJug = 0;
        int steps = 1;

        while (fromJug != d && toJug != d) {
            int pour = min(fromJug, to - toJug);
            toJug += pour;
            fromJug -= pour;
            steps++;

            if (fromJug == d || toJug == d) break;

            if (fromJug == 0) {
                fromJug = from;
                steps++;
            }

            if (toJug == to) {
                toJug = 0;
                steps++;
            }
        }
        return steps;
    }

    int minSteps(int m, int n, int d) {
        if (d == 0) return 0;
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        return min(solve(m, n, d), solve(n, m, d));
    }
};
// Time Complexity: O((m+n)/gcd(m,n)) where m and n are the capacities of the jugs
// Space Complexity: O(1) as we are using only a constant amount of extra space