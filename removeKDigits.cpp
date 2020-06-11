//Link:  https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int n=num.size();
        if(k>n)
            return "0";
        char c,stk[n];
        int top=0,digits=n-k,idx=0;
        string sol="";
        for(int i=0;i<n;i++)
        {
            c=num[i];
            //in this loop we keep removing the previous element where the last element was greater
            //basically a downhill.
            while(top>0&&stk[top-1]>c&&k)
            {
                top--;
                k--;
            }
            stk[top++]=c;
        }
        //count number of zeros in front
        //we will traverse only till digits coz after removing k chars we are left with digits chars
        //the other case is 11234 an increasing sequence in that case last k elements are trimmed
        // the above while loop has no impact on such case.
        while(idx<digits&&stk[idx]=='0')
            idx++;
        if(idx==digits)
            return "0";
        //here we are appending the stk char excluding the front '0' to the solution string.
        for(int i=idx;i<digits;i++)
            sol=sol+stk[i];
        return sol;
    }
};
