class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        vector<int> res = num;

        int i = 0, j = n - 1;
        while (i < j) {
            res[j] = res[i];
            i++; j--;
        }

        if (res > num) return res;

        int carry = 1;
        int mid = n / 2;

        i = (n % 2 == 0) ? mid - 1 : mid;
        j = mid;

        while (i >= 0) {
            int sum = res[i] + carry;
            carry = sum / 10;
            res[i] = sum % 10;
            res[j] = res[i]; 

            i--;
            j++;
        }

        if (carry) {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }

        return res;
    }
};
// Time Complexity: O(n) where n is the number of digits in the input number
// Space Complexity: O(n) as we are using an extra vector to store the result