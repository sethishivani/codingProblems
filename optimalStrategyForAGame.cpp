//Link:  https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1/?track=amazon-dynamic-programming&batchId=192

int maximumAmount(int arr[], int n)
{
    //sol[i][j] represents maximum coins that we can collect from arr[i] to arr[j]
    int sol[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sol[i][j]=0;
    }
    // there are 2 base cases:
    // 1. sol[i][i]=arr[i]
    // 2. sol[i][j]=max(arr[i],arr[j]) when i+1=j
    for(int i=0;i<n;i++)
        sol[i][i]=arr[i];
    for(int i=0;i<n-1;i++)
        sol[i][i+1]=max(arr[i],arr[i+1]);
    int gap=2,b,e;
    // for any position sol[i][j] = arr[i]+ min(sol[i+1][j-1],sol[i+2][j])
                      //            arr[j]+ min(sol[i][j-2],sol[i+1][j-1])
    for(int i=2;i<n;i++)
    {
        for(int j=0;j+gap<n;j++)
        {
            b=j;
            e=j+gap;
            sol[b][e]=max(arr[b]+min(sol[b+1][e-1],sol[b+2][e]),arr[e]+min(sol[b][e-2],sol[b+1][e-1]));
        }
        gap+=1;
    }
    return sol[0][n-1];
}
