//Link:  https://leetcode.com/problems/task-scheduler/

//Amazing problem
//we check the maximum number of times a letter is occuring lar and then we count how many letters are occuring max number of times.
//we make use of space=(n+1)*(lar-1) and then increment space according to occ.
//now 2 cases are possible either word count is so big that they rearrange themselves to make n-gaps execution for letters thatis possible only if
//calculated space < tasks.size(). Otherwise we need space, so we return max of the two.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int sz=tasks.size(),lar=0,occ=0,space;
        for(int i=0;i<sz;i++)
        {
            count[tasks[i]-65]++;
            if(count[tasks[i]-65]>lar)
                lar=count[tasks[i]-65];
        }
        for(int i=0;i<26;i++)
        {
            if(count[i]==lar)
                occ++;
        }
        space=(n+1)*(lar-1);
        space+=occ;
        return max(space,sz);
    }
};
