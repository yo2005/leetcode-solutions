class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;
        for(auto x: points){
            int z=x[0]*x[0]+x[1]*x[1];
            pq.push({z,x});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;


        
    }
};
