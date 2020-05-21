//link: https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/?track=amazon-dynamic-programming&batchId=192
int subsequenceCount(string S, string T)
{
    int n=T.size(),m=S.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[i][j]=1;
                continue;
            }
            else if(j==0)
            {
                dp[i][j]=0;
                continue;
            }
            //in if condition we say if in S and T  current char are equal then,
                //we consider [i-1][j-1] coz it has count of all the elements
                //for which this would be the next element and we consider
                //[i][j-1] which says if we dont consider this character to
                //be the next element of pattern i.e. those sequences which formed
                //combination with previos occurance of same character.
            //else if current char is not equal then,
                //we consider [i][j-1] which says we dont consider this character to
                //be the next element of pattern
            if(S[j-1]==T[i-1])
                dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%1000000007;
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    return dp[n][m];
}
