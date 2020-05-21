//Link : https://practice.geeksforgeeks.org/problems/convex-hull/0
#include <bits/stdc++.h>
using namespace std;
int shdswap(pair <int, int>& p, pair <int, int>& q, pair <int, int>& r)
{
    //r is to be tested;
    int x1,x2,y1,y2,res;
    x1=p.first-q.first;
    x2=p.first-r.first;
    y1=p.second-q.second;
    y2=p.second-r.second;
    res=x1*y2-x2*y1;
    if(res==0)
        return 2;
    else if(res>0)
        return 1;
    return 0;
}
bool qIsFarther(pair <int, int>& p, pair <int, int>& q, pair <int, int>& r)
{
    int x1,x2,y1,y2,l1,l2;
    x1=p.first-q.first;
    x2=p.first-r.first;
    y1=p.second-q.second;
    y2=p.second-r.second;
    l1=x1*x1+y1*y1;
    l2=x2*x2+y2*y2;
    if(l1>l2)
        return 1;
    return 0;
}
int main() {
	int t,n,x,y,p,q;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<pair <int, int> > vec(n);
	    set<pair <int, int> > hull;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x>>y;
	        vec[i]={x,y};
	    }

        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        n=vec.size();
	    if(n<=2)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    p=0;
	    for(int i=1;i<n;i++)
	    {
	        if(vec[i].first<vec[p].first)
	            p=i;
	    }
	    pair <int, int> beg=vec[p];
	    while(1)
	    {
	        hull.insert(vec[p]);
	        q=(p+1)%n;
	        for(int i=0;i<n;i++)
	        {
              if(shdswap(vec[p],vec[q],vec[i])==1){
                  q=i;
              }
              else if(shdswap(vec[p],vec[q],vec[i])==2)
              {
                  if(qIsFarther(vec[p],vec[q],vec[i])==0)
                      q=i;
              }
	        }
	        p=q;
	        if(vec[p].first==beg.first&&vec[p].second==beg.second)
	            break;
	    }
	    bool f=0;
	    for(auto it=hull.begin();it!=hull.end();it++){
	        if(f==0)
	        {
	            f=1;
	            cout<<(*it).first<<" "<<(*it).second;
	            continue;
	        }
	        cout<<", "<<(*it).first<<" "<<(*it).second;}
	    cout<<endl;
	}
	return 0;
}
