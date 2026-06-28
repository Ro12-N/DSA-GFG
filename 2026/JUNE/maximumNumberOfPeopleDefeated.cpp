class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int i=1;
        while((i*i)<=p){
            p-=(i*i);
            i++;
        }
        return i-1;
    }
};

// TC : O(sqrt(p)) where p is the number of people.
// SC : O(1) as we are using constant space.


class Solution {
public:
    int maxPeopleDefeated(int p) {
        long long low = 0, high = 100000;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            if (sum <= p)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};
// TC : O(log n) where n is the number of people.
// SC : O(1) as we are using constant space.