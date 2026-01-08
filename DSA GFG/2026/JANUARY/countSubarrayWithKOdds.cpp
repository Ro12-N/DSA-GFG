class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int odd=0;
        mp[0]=1;
        int ans=0;
        for(auto i:arr){
            if(i%2) odd++;
            if(mp.count(odd-k)) ans+=mp[odd-k];
            mp[odd]++;
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)




 // Alternate Approach:

// class Solution {
//   public:
//   int solve(vector<int>& arr, int k){
//       int ans=0;
//       int i=0;
//       int odd=0;
//       for(int j=0;j<arr.size();j++){
//           if(arr[j]%2) odd++;
//           while(odd>k){
//               if(arr[i]%2) odd--;
//               i++;
//           }
//           ans+=j-i+1;
//       }
//       return ans;
//   }
//     int countSubarrays(vector<int>& arr, int k) {
//         // code here
//        return solve(arr,k)-solve(arr,k-1);
//     }
// };
// Time Complexity: O(N)
// Space Complexity: O(1)