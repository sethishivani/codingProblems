//Link:  https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1/?track=amazon-arrays&batchId=192
//solve it using 2 arrays
int maxIndexDiff(int arr[], int n)
{
    int leftmin[n]; //take and store smaller element from left to right
    int rightmax[n]; //take and store larger element form right to left
    leftmin[0]=arr[0];
    for(int i=1;i<n;i++)
        leftmin[i]=min(leftmin[i-1],arr[i]);
    rightmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        rightmax[i]=max(rightmax[i+1],arr[i]);
    int lt=0,rt=0,dist=0;
    while(rt<n)
    {
        while(rt<n&&leftmin[lt]<=rightmax[rt])
            rt+=1;
        dist=max(dist,rt-lt-1);
        while(lt<rt&&leftmin[lt]>rightmax[rt])
            lt+=1;
    }
    return dist;

}
