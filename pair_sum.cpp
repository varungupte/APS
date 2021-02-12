#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,i,a,b,sum,tmp;
        cin>>n>>q;
        vector<ll> v(n-1),ve(n-1,0),vo(n-1,0);
        ll prev=0;
        for(i=0;i<n-1;i++)
        {
            cin>>v[i];
            if(i%2==0)
            {
                if(i>=2)
                    ve[i]=v[i]+ve[i-2];
                else
                    ve[i]=v[i];
            }
            else
            {
                if(i>=2)
                    vo[i]=v[i]+vo[i-2];
                else
                    vo[i]=v[i];
            }
            v[i]+=prev;
            prev=v[i]; 
        }
        for(i=0;i<q;i++)
        {
            cin>>a>>b;
            a--;
            b--;
            if(a>b)
                swap(a,b);
        
            if((b-a)%2==0)
            {
                cout<<"UNKNOWN"<<endl;   
            }
            else
            {
                tmp=0;
                b--;
                if(a==0)
                    sum=v[b];
                else
                    sum=v[b]-v[a-1];
                
                ll p,q1;
                p=b-1;
                if(p%2==0 &&  p>=0)
                {
                    p=ve[p];
                }
                else if(p>=0)
                    p=vo[p];
                else
                    p=0;
                
                if((a-1)%2==0 && a-1>=0)
                    q1=ve[a-1];
                else if(a-1>=0)
                    q1=vo[a-1];
                else
                    q1=0;
                
                tmp= 2*(p-q1);
                
                
                ll ans=sum-tmp;
                cout<<ans<<endl;
                
            }
        }
    }
    return 0;
}