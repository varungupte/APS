#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i,a,b,c,prevb=-1,prevc=-1;
        for(i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            if(a==1)
            {
                cout<<"YES"<<endl;
                prevb=b;
                prevc=c;
            }
            else
            {
                if(b==c)
                {
                    prevb=b;
                    prevc=c;
                    cout<<"YES"<<endl;
                }
                else
                {
                    if(prevb==-1)
                        cout<<"NO"<<endl;
                    else if(b>=prevb && b>=prevc)
                    {
                        if(c>=prevb && c>=prevc)
                            cout<<"NO"<<endl;
                        else
                        {
                            cout<<"YES"<<endl;
                            if(prevb>=prevc)
                            {
                                prevb=b;
                                prevc=c;
                            }
                            else
                            {
                                prevc=b;
                                prevb=c;
                            }
                        }
                    }
                    else if(c>=prevb && c>=prevc)
                    {
                        cout<<"YES"<<endl;
                        if(prevc>=prevb)
                        {
                            prevb=b;
                            prevc=c;
                        }
                        else
                        {
                            prevc=b;
                            prevb=c;
                        }
                    }
                    else
                        cout<<"NO"<<endl;
                }
            }
        }
    }
	return 0;
}