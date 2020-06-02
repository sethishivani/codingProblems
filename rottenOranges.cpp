//Link:  https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/?track=amazon-graphs&batchId=192

//the most important concept here is that we make use of bfs tech here we insert all the rotten nodes first and start calculating distance og non-rotten nodes
// from these rotten nodes calculating the minimum distance
int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    queue<pair<int,int> > q;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==2)
                q.push({i,j});
        }
    }
    int x[]={0,0,-1,1};
    int y[]={-1,1,0,0};
    int d=0,s,px,py;
    pair<int,int> tmp;
    while(!q.empty())
    {
        s=q.size();
        //cout<<s<<endl;
        for(int i=0;i<s;i++)
        {
            tmp=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                px=tmp.first+x[i];
                py=tmp.second+y[i];
                if(check(px,py,R,C)&&matrix[px][py]==1)
                {
                    //we mark all the non-rotten nodes as rotten
                    matrix[px][py]=2;
                    q.push({px,py});
                }
            }
        }
        d+=1;
    }
    if(left(matrix,R,C))
        return -1;
    return d-1;
}
