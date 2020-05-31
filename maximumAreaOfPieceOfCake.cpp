//Link:  https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // take care of 0 to 1st element and last element to h/w while calculating max size
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long int m1=horizontalCuts[0],m2=verticalCuts[0],diff,sol;
        int hs=horizontalCuts.size(),vs=verticalCuts.size();
        for(int i=1;i<hs;i++)
        {
            diff=horizontalCuts[i]-horizontalCuts[i-1];
            if(m1<diff)
                m1=diff;
        }
        if(m1<h-horizontalCuts[hs-1])
            m1=h-horizontalCuts[hs-1];
        for(int i=1;i<vs;i++)
        {
            diff=verticalCuts[i]-verticalCuts[i-1];
            if(m2<diff)
                m2=diff;
        }
        if(m2<w-verticalCuts[vs-1])
            m2=w-verticalCuts[vs-1];
        // cout<<m1<<'\t'<<m2;
        sol=(m1*m2)%1000000007;
        return sol;
    }
};
