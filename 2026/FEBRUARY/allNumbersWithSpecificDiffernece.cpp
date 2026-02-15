class Solution {
public:

    int digitSum(long long x){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    bool isValid(long long x, int d){
        return (x - digitSum(x)) >= d;
    }

    int getCount(int n, int d) {
        
        long long low = 1, high = n;
        long long ans = n + 1;   
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            
            if(isValid(mid, d)){
                ans = mid;
                high = mid - 1;   
            }
            else{
                low = mid + 1;
            }
        }
        
        if(ans == n + 1) return 0;   
        
        return n - ans + 1;
    }
};

// Time Complexity: O(log n * log n) due to the binary search and digit sum calculation
// Space Complexity: O(1) as we are using only a constant amount of extra space