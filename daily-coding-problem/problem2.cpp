#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	std::vector<int> v1;
	std::vector<int> v2(n,0);
	for(int i=0;i<n;i++)
	{
		int value;
		cin>>value;
		v1.push_back(value);
	}
	int forward=1,backward=1;
	for(int i=0;i<n;i++)
	{
		v2[i]=forward;
		forward=forward*v1[i];
	}
	for(int i=0;i<n;i++)
	{
		v2[n-1-i]=v2[n-1-i]*backward;
		backward=backward*v1[n-1-i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<v2[i]<<" "; 
	}
	return 0;
}
