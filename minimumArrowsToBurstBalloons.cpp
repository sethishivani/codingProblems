//Link:  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),sz=0;
        if(n==0)
            return 0;
        sort(points.begin(),points.end());
        vector<vector<int>> sol;
        sol.push_back(points[0]);
        for(int i=1;i<n;i++)
        {
            if(sol[sz][1]>=points[i][0])
            {
                sol[sz][0]=points[i][0];
                sol[sz][1]=min(sol[sz][1],points[i][1]);
            }
            else
            {
                sol.push_back(points[i]);
                sz+=1;
            }
        }
        return sz+1;
    }
};
