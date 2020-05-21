//Link:  https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1/?track=amazon-arrays&batchId=192
int kadane(int arr[], int n)
{
    int ksum=arr[0],local=0;
    for(int i=0;i<n;i++)
    {
        local+=arr[i];
        if(local>ksum)
            ksum=local;
        if(local<0)
            local=0;
    }
    return ksum;
}
int circularSubarraySum(int arr[], int n){
    int arrsum=0;
    for(int i=0;i<n;i++)
        arrsum+=arr[i];
    //calculating sum using normal kadane
    int ksum;
    ksum=kadane(arr,n);
    //calculate circular sum
    //1. calculate max neg patch using kadane
    //2. Substarct max neg from rest of array i.e arrsum+maxneg
    int maxneg;
    for(int i=0;i<n;i++)
        arr[i]=arr[i]*-1;
    maxneg=kadane(arr,n);
    // take care of the test case where entire array is the maxneg patch, now maxneg is max sum possible
    if(arrsum!=(maxneg*-1))
        arrsum+=maxneg;
    if(arrsum>ksum)
        return arrsum;
    return ksum;
}
