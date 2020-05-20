//Link:  https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1/?track=amazon-arrays&batchId=192
//solve it using 2 pointers
long long maxArea(long long arr[], int len)
{
    int lt=0,rt=len-1;
    long long sol=0;
    while(lt<rt)
    {
        sol=max(sol,(rt-lt)*min(arr[rt],arr[lt]));
        if(arr[lt]<arr[rt])
            lt+=1;
        else
            rt-=1;
    }
    return sol;
}
