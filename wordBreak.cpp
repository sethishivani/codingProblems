//Link:  https://practice.geeksforgeeks.org/problems/word-break1352/1/?track=amazon-dynamic-programming&batchId=192



int wordBreak(string A, vector<string> &B) {
    string tmp;
    unordered_set<string> st;
    int n=B.size();
    for(int i=0;i<n;i++)
        st.insert(B[i]);
    vector<int> pos;
    // here we keep a track of all the positions till which the word could be found in pos. Then while looping we check if we can get the current word starting from
    // the diffrent positions stored in the pos vector.
    pos.push_back(-1);
    int len=A.size(),s;
    for(int i=0;i<len;i++)
    {
        s=pos.size();
        for(int j=s-1;j>=0;j--)
        {
            tmp=A.substr(pos[j]+1,i-pos[j]);
            if(st.find(tmp)!=st.end())
            {
                pos.push_back(i);
                break;
            }
        }
    }
    if(pos.back()==len-1)
        return 1;
    return 0;
}
