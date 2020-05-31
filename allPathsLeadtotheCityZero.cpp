//Link:  https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      // to store both front edge and back edge.
        unordered_map<int,vector<int> > ce;
        unordered_map<int,vector<int> > be;
        int ans=0;
        int sz=connections.size(),x;
        for(int i=0;i<sz;i++)
        {
            ce[connections[i][0]].push_back(connections[i][1]);
            be[connections[i][1]].push_back(connections[i][0]);
        }
        // to keep a track of what all elements are already pointing to '0'
        vector<bool > flag(n,0);
        flag[0]=1;
        queue<int> que;
        que.push(0);
        int tp,val;
        // apply normal bfs using a queue making use of both fe nd be
        // only in case of a front edge we add 1.
        // a back edge value is already pointing to '0'
        while(!que.empty())
        {
            x=que.size();
            for(int i=0;i<x;i++)
            {
                tp=que.front();
                que.pop();
                if(ce.find(tp)!=ce.end())
                {
                    for(int j=0;j<ce[tp].size();j++)
                    {
                        val=ce[tp][j];
                        if(flag[val]==0)
                        {
                            que.push(val);
                            flag[val]=1;
                            ans+=1;
                        }
                    }
                }
                if(be.find(tp)!=be.end())
                {
                    for(int j=0;j<be[tp].size();j++)
                    {
                        val=be[tp][j];
                        if(flag[val]==0)
                        {
                            que.push(val);
                            flag[val]=1;
                        }
                    }
                }

            }

        }
        return ans;
    }
};
