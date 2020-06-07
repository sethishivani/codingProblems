//Link:  https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> sol(amount+1,0);
        sol[0]=1;
        int n=coins.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i]<=j)
                    sol[j]=sol[j]+sol[j-coins[i]];
            }
        }
        return sol[amount];
    }
};
