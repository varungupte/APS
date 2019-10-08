#include <iostream>
#define ll long long int
using namespace std;

bool fun(ll a,ll b,ll c,ll s){
    if(s<0){
        return false;
    }
    if(s==0){
        return true;
    }
    if(c>0 && s>=3){
        return fun(a,b,c-1,s-3)|| fun(a,b,c-1,s);
    }else if(b>0 && s>=2){
        return fun(a,b-1,c,s-2)|| fun(a,b-1,c,s);
    }else if(a>0 && s>=1){
        return fun(a-1,b,c,s-1)|| fun(a-1,b,c,s);
    }
    return false;
}

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll a,b,c;
	    cin>>a>>b>>c;
	    ll s=a+2*b+3*c;
	    if(s%2==1){
	        cout<<"NO\n";
	    }else{
	        s=s/2;
	        if(fun(a,b,c,s)){
	            cout<<"YES\n";
	        }else{
	            cout<<"NO\n";
	        }
	    }
	}
	return 0;
}
