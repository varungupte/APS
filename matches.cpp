#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin>>t;
    map<ll,ll> mp;
    mp[0]=6;
    mp[1]=2;
    mp[2]=5;
    mp[3]=5;
    mp[4]=4;
    mp[5]=5;
    mp[6]=6;
    mp[7]=3;
    mp[8]=7;
    mp[9]=6;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        a=a+b;
        ll ans=0;
        if(a==0)
            cout<<mp[a]<<endl;
        else
        {
            while(a>0)
        {
            ll r=a%10;
            ans+=mp[r];
            a/=10;
        }
        cout<<ans<<endl;    
        }
        
    }
	return 0;
}