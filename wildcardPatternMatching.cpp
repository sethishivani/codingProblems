//Link:  https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1/?track=amazon-dynamic-programming&batchId=192


int wildCard(string pattern,string str)
{
    int n=pattern.size(),m=str.size();
    vector< vector<int> > vec(n+1,vector<int> (m+1,0));
    vec[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(pattern[i-1]=='*'&&vec[i-1][0]==1)
            vec[i][0]=1;
        for(int j=1;j<=m;j++)
        {
          // if the current element of pattern matches the current element of str then if not considering
          // this element in bot str and pattern we check vec[i-1][j-1] if that is a part of sec=quence then
          //only this can continue the sequence
            if(pattern[i-1]=='?'||pattern[i-1]==str[j-1])
                vec[i][j]=vec[i-1][j-1];
          // vec[i-1][j-1] coz * can take shape of any char
          // vec[i-1][j] coz we can assume * as /0
          // vec[i][j-1] coz * can be multiple chars
            if(pattern[i-1]=='*')
                vec[i][j]=(vec[i-1][j]||vec[i][j-1]||vec[i-1][j-1]);
        }
    }
    return vec[n][m];
}
