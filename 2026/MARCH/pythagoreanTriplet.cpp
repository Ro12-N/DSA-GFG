class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
       int n=arr.size();
       unordered_set<int>st;
       for(int i=0;i<n;i++){
               st.insert(arr[i]*arr[i]);
       }
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               if(st.count(arr[i]*arr[i]+arr[j]*arr[j])) return true;
           }
       }
       return false;
    }
};
// Time Complexity: O(n^2) where n is the size of the input array.
// Space Complexity: O(n) where n is the size of the input array.



// Another approach using factorization
class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());

        for (int b : arr) {
            long long b2 = 1LL * b * b;

            for (long long d = 1; d * d <= b2; d++) {
                if (b2 % d) continue;

                long long x = d;
                long long y = b2 / d;

                if ((x + y) % 2) continue;

                long long c = (x + y) / 2;
                long long a = (y - x) / 2;

                if (st.count(a) && st.count(c))
                    return true;
            }
        }

        return false;
    }
};
// Time Complexity: O(n * sqrt(max(arr))) where n is the size of the input array and max(arr) is the maximum element in the array.
// Space Complexity: O(n) where n is the size of the input array.