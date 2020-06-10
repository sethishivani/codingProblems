//Link:  https://leetcode.com/problems/wiggle-subsequence/

// we keep a tap on 2 counters up and down. Their initial value is set 1.
// as we find an element less than previous element we update down with up + 1.
// vice versa with down.

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up=1,down=1,n=nums.size();
        if(n==0)
            return n;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
                up=down+1;
            else if(nums[i-1]>nums[i])
                down=up+1;
        }
        return max(up,down);
    }
};
