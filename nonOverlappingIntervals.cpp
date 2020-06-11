//Link:  https://leetcode.com/problems/non-overlapping-intervals/

// the basic logic is to sort the elements in increasing order of intervals.end
bool compare(const vector<int>& a,const vector<int>& b)
{
    if(a[1]<b[1])
        return 1;
    return 0;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        if(n<=1)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int e=intervals[0][1],cnt=1;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=e){
                cnt++;
                e=intervals[i][1];
            }
        }
        return n-cnt;
    }
};
