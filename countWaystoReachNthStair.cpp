//Link:  https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1/?track=amazon-dynamic-programming&amp;batchId=192

long long countWays(int m){
    int arr[m+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=m;i++)
        arr[i]=(arr[i-1]+arr[i-2])%1000000007;
    return arr[m];
}
