class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
       auto dist=[](const vector<int>&curr){
           return 1LL*curr[0]*curr[0]+1LL*curr[1]*curr[1];
       };
       
        nth_element(points.begin(),points.begin()+k,points.end(),
        [&](const vector<int>&a,const vector<int>&b){
                    return dist(a)<dist(b);
       });
       points.resize(k);
       return points;
       
    }
};

//O(n)


// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<int, int>> pq; // {distance^2, index}

//         for (int i = 0; i < points.size(); ++i) {
//             int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
//             pq.push({dist, i});
//             if (pq.size() > k) pq.pop(); 
//         }

//         vector<vector<int>> res;
//         res.reserve(k);
//         while (!pq.empty()) {
//             res.push_back(points[pq.top().second]);
//             pq.pop();
//         }

//         return res;
//     }
// };


// O(nlogk)
// O(K)
