//Link:  https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1/?track=amazon-dynamic-programming&batchId=192

// for 1st appearance of a it can be starting of a new sequence or it may or may not be a part of earlier a's
// for 1st appearance of b it can be starting of a new b sequence with existing a's sequence or it may or may not be a part of earlier b's
// for 1st appearance of c it can be starting of a new c sequence with existing b's sequence or it may or may not be a part of earlier c's
int fun(string &str) {
    long long int n=str.size(),ac=0,bc=0,cc=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            ac=(2*ac+1)%1000000007;
        }
        else if(str[i]=='b')
        {
            bc=(2*bc+ac)%1000000007;
        }
        else
        {
            cc=(2*cc+bc)%1000000007;
        }
    }
    return cc;
}
