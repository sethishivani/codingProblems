//Link : https://practice.geeksforgeeks.org/problems/max-length-chain/1/?track=amazon-dynamic-programming&batchId=192

bool compare(struct val a, struct val b)
{
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
    vector<int> vec(n,1);
    sort(p,p+n,compare);
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(p[i].first>p[j].second)
                vec[i]=max(vec[i],vec[j]+1);
        }
    }
    return vec[n-1];
}
