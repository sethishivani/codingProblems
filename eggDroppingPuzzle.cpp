//Link:  https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1/?track=amazon-dynamic-programming&batchId=192

int eggDrop(int n, int k)
{
    //the formula says there are 2 cases at each floor egg breaks or not
    // n floors testing at kth floor x eggs
    // if egg breaks check for k-1 floor and x-1 eggs ----- <1>
    // if egg doesn't break check for n-k floors and x eggs ------- <2>
    // we take max of <1> and <2>
    // we loop for all the floors and see which givs us the min val
    int arr[n+1][k+1];
    arr[0][0]=0;
    //one of the base case is that if only 0 floors left then we need 0 trials.
    for(int i=1;i<=n;i++){
        arr[i][1]=1;
        arr[i][0]=0;
    }
    for(int i=0;i<=k;i++){
        arr[0][i]=0;
        arr[1][i]=i;
    }

    int tmp,val,brks,dbrk;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            val=INT_MAX;
            for(int f=j;f>=1;f--)
            {
                brks=arr[i-1][f-1];
                dbrk=arr[i][j-f];
                tmp=max(brks,dbrk);
                val=min(val,tmp);
            }
            // we add 1 here coz it counts this current drop.
            arr[i][j]=val+1;
        }
    }
    return arr[n][k];
}
