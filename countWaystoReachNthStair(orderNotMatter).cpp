//Link:  https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/?track=amazon-dynamic-programming&batchId=192

long long countWays(int m){
    vector<long long> vec(m+1,1);
    for(int i=2;i<=m;i++)
        vec[i]=vec[i]+vec[i-2];
    return vec[m];
}
