//Link:  https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1/?track=amazon-dynamic-programming&batchId=192


int binser(vector<int> sol,int num)
{
    int b=0,e=sol.size()-1,mid;
    while(b<=e)
    {
        mid=(b+e)/2;
        // Please handle the case when 2 the num to be found already exists
        // int the sol vector
        if(sol[mid]==num||(sol[mid]>num&&sol[mid-1]<num))
            return mid;
        else if(sol[mid]>num)
            e=mid-1;
        else
            b=mid+1;
    }
    return b;
}
// Function to find longest subsequence
int longestSubsequence(int n, int a[]){
    if(n==0)
        return 0;
    vector<int> sol;
    int s=0,pos;
    sol.push_back(a[0]);
    s=1;
    for(int i=1;i<n;i++)
    {
      // if new element has to be pushed it is greater than the last element
        if(sol[s-1]<a[i]){
            sol.push_back(a[i]);
            s+=1;
        }
        // if an element is smaller than the first element
        else if(sol[0]>a[i])
            sol[0]=a[i];
        // find place for rest of elements
        // should be smaller than me but larger than the previous
        else
        {
            pos=binser(sol,a[i]);
            sol[pos]=a[i];
        }
    }
    return s;
}
