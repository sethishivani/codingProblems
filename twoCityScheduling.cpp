//Link:  https://leetcode.com/problems/two-city-scheduling/

bool comparator(const vector<int> &a,const vector<int> &b)
{
    return abs(a[1]-a[0])>abs(b[1]-b[0]);
}
//The concept here is to check the diffrence of cost when one flies to A or B.
//The max we can save sooner will the value be picked
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // vector< pair<int,int> > vec;
        int n=costs.size();
        // for(int  i=0;i<n;i++)
        // {
        //     vec.push_back({costs[i][0],costs[i][1]});
        // }
        sort(costs.begin(),costs.end(),comparator);
        int i=0,sol=0,a=0,b=0;
        while(i<n)
        {
            if(costs[i][0]<costs[i][1])
            {
                if(a<n/2){
                    sol+=costs[i][0];
                    a+=1;
                }
                else
                {
                    sol+=costs[i][1];
                    b+=1;
                }
            }
            else
            {
                if(b<n/2){
                    sol+=costs[i][1];
                    b+=1;
                }
                else
                {
                    sol+=costs[i][0];
                    a+=1;
                }
            }
            i+=1;
        }
        return sol;
    }
};
