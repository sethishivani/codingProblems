//Link:  https://practice.geeksforgeeks.org/problems/cutted-segments1642/1/?track=amazon-dynamic-programming&batchId=192
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> vec(n+1,0);
    vector<int> len(3);
    len[0]=x;
    len[1]=y;
    len[2]=z;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //j==len[i] this condt is used because the first cut is possible at this
            //time only i.e. from the corner.
            if(j==len[i])
                vec[j]=max(vec[j],1);
            //vec[j-len[i]]!=0 this is checked coz to add this cut j-len[i] position
            //should have a cut.
            if(j>len[i]&&vec[j-len[i]]!=0)
                vec[j]=max(vec[j],vec[j-len[i]]+1);
        }
    }
    return vec[n];
}
