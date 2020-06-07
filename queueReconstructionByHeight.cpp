//Link:  https://leetcode.com/problems/queue-reconstruction-by-height/


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size(),after,curr,loc,x;
        vector<vector<int>> sol;
        sort(people.begin(),people.end());
        vector<int> pos(n,-1);
        for(int i=0;i<n;i++)
        {
            after=people[i][1];
            curr=people[i][0];
            for(int j=0;j<n;j++)
            {
                if(after==-1)
                    break;
                x=pos[j];
                if(x==-1||people[x][0]>=curr)
                {
                    after--;
                }
                loc=j;
            }
            pos[loc]=i;
        }
        for(int i=0;i<n;i++)
            sol.push_back(people[pos[i]]);
        return sol;
    }
};
