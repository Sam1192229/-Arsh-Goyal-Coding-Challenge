class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int maxans=INT_MIN;
        for(int i=0;i<points.size();i++){
            int x= points[i][0];
            int y= points[i][1];
           
            while(!pq.empty() &&  (x-pq.top().second)>k){
                pq.pop();
            }
            if(!pq.empty() &&  (x-pq.top().second)<=k){
                maxans=max(maxans, pq.top().first+y+x);
            }
            pq.push({y-x,x});
        }
        return maxans;
    }
};