//link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1/?track=amazon-dynamic-programming&batchId=192

//we check if the current word  i.e. s1[i-1]==s2[j-1] then we add 1 to the matching
//formend removing these elements
//Else what we do is we check if we remove 1 element from s1 or if we remove one
//element from s2 which gives us larger value 
int lcs(int x, int y, string s1, string s2){
    vector< vector <int> > sol (x+1, vector<int> (y+1,0));
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                sol[i][j]=max(sol[i][j-1],sol[i-1][j]);
        }
    }
    return sol[x][y];
}
