#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		int value;
		cin>>value;
		m[value]++;
	}
	int k;
	cin>>k;
	for(auto i:m)
	{
		int kk=k-i.first;
		if(m.find(kk)!=m.end())
		{
			cout<<"true";
			return 0;
		}
	}
	cout<<"false";
	return 0;
}

O(n)=O(1) i.e constant
