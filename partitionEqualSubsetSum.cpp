//Link:  https://leetcode.com/problems/partition-equal-subset-sum/

//for each element check if it was previously set to 1 or we check if we go to prev row and check going back that many elements to see if it was
// set to 1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return 0;
        sum=sum/2;
        int arr[n+1][sum+1];
        vector< vector <bool> > vec (n+1, vector<bool> ( sum+1 ,0));
        for(int i=0;i<=n;i++)
            vec[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<nums[i-1]){
                    vec[i][j] = vec[i-1][j];
                    continue;
                }
                vec[i][j]=(vec[i-1][j]||vec[i-1][j-nums[i-1]]);
            }
        }
        return vec[n][sum];
    }
};
