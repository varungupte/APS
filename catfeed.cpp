#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,f=0,x;
        cin>>n>>m;
        vector<ll> v(n,0);
        // v.clear();
        ll i,prev;
        for(i=0;i<m;i++)
        {
            cin>>x;
            prev=i/n;
            // cout<<prev<<" ";
            if(v[x-1]==prev)
                v[x-1]++;
            else
            {
                f=1;
                // break;
            }
        }
        if(f==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
	return 0;
}