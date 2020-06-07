//Link:  https://leetcode.com/problems/the-k-strongest-values-in-an-array/

int ele;
bool compare(const int a,const int b)
{
    if(abs(a-ele)>abs(b-ele))
        return 1;
    else if(abs(a-ele)==abs(b-ele))
    {
        if(a>b)
            return 1;
        return 0;
    }
    return 0;
}
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size(),m;
        vector<int> sol(k);
        sort(arr.begin(),arr.end());
        m=(n-1)/2;
        ele=arr[m];
        // cout<<ele<<endl;
        sort(arr.begin(),arr.end(),compare);
        // for(int i=0;i<n;i++)
        //     cout<<arr[i]<<'\t';
        // cout<<endl;
        for(int i=0;i<k;i++)
        {
            sol[i]=arr[i];
        }
        return sol;
    }
};
