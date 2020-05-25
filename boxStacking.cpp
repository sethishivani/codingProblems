//Link : https://practice.geeksforgeeks.org/problems/box-stacking/1/?track=amazon-dynamic-programming&batchId=192

struct val
{
    int ln;
    int br;
    int ht;
};
bool compare(struct val a, struct val b)
{
    if(a.ln!=b.ln)
        return a.ln<b.ln;
    return a.br<b.br;
}
int maxHeight(int height[],int width[],int length[],int n)
{
    int s=3*n;
    struct val arr[s];
    vector<int> sol(s,0);
    int ans;
    for(int i=0;i<n;i++)
    {
        //*****important******
        // we try to store data i.e. br>ln
        arr[i*3].ln=min(width[i],height[i]);
        arr[i*3].br=max(width[i],height[i]);
        arr[i*3].ht=length[i];
        arr[i*3+1].ln=min(height[i],length[i]);
        arr[i*3+1].br=max(height[i],length[i]);
        arr[i*3+1].ht=width[i];
        arr[i*3+2].ln=min(width[i],length[i]);
        arr[i*3+2].br=max(length[i],width[i]);
        arr[i*3+2].ht=height[i];
    }
    sort(arr,arr+s,compare);
    sol[0]=arr[0].ht;
    ans=sol[0];
    int tmp;
    for(int i=1;i<s;i++)
    {
        sol[i]=arr[i].ht;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j].ln<arr[i].ln&&arr[j].br<arr[i].br){
                tmp=arr[i].ht+sol[j];
                if(tmp>sol[i])
                    sol[i]=tmp;
            }
        }
        if(ans<sol[i])
            ans=sol[i];
    }
    // for(int i=0;i<s;i++)
    //     cout<<arr[i].ln<<'\t'<<arr[i].br<<'\t'<<arr[i].ht<<endl;
    // for(int i=0;i<s;i++)
    //     cout<<sol[i]<<'\t';
    // cout<<endl;
    return ans;
}
