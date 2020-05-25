//Link:  https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps4102/1/?track=amazon-dynamic-programming&batchId=192

int minimumJumps(int arr[], int n){
    vector<int> sol(n);
    //jumps keep a track of jumps needed till now to reach this place
    //maxreach keeps a track of maximum index that we can reach
    //movesleft keeps a track of how many steps can be taken in this jump count
    int maxreach=INT_MIN,jumps=0,movesleft=0,i=0;
    while(i<n)
    {
        sol[i]=jumps;
        maxreach=max(maxreach,(arr[i]+i));
        if(movesleft==0){
            if(maxreach<=i)
                return -1;
            movesleft=maxreach-i;
            jumps+=1;
        }
        movesleft--;
        i+=1;
    }
    return sol[n-1];
}
