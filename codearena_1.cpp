/*PROBLEM STATEMENT
Exams are approaching soon and everyone tries to get ready for them. So, Omar decides to begin studying his subjects. He has N subjects and he wants to study M of them today. According to Omar, every subject has an interest level,  which indicates how much Omar likes that subject. Unfortunately, Omar feels bored easily, so he decides to choose a collection of interesting and boring subjects. Actually, Omar wants to choose M subjects such that the summation S of the absolute difference between every two adjacent subjects' interest levels is maximum as possible. Omar will put the selected M subjects in a group in the same order as described in the input, and then he will proceed to calculate S.

Please help Omar and rescue him from boredom

Input:

First line of the input contains an integer T denoting the number of test cases. 
First line of every test-case contains two space separated integers N and M. 
Second line of every test case contains N space separated integers denoting the interest level for  subject.

*Output: *

For each case, print the above described S in a separate line.

Constraints:
.
.
SAMPLE INPUT 
1
5 3
100 50 3000 4000 40
SAMPLE OUTPUT 
7910
Explanation
You should choose the following group in the same order that appears in the input. .

*/






#include<bits/stdc++.h>
using namespace std;
long long int result=0;
void maxcal(vector<long long int> v,int n,int m,long long int value,int jj)
{
	long long int aa=0;
	if(m==0)
	{
        if(value>=result)
        {
        	result=value;
        	// return value;
        	return;
        }
	}
	else{
		for(int i=jj;i<n-m;i++)
		{
			for(int j=i+1;j<n-m+1;j++)
			{
				value=value+abs(v[i]-v[j]);
				maxcal(v,n,m-1,value,j);
				value=value-abs(v[i]-v[j]);
			}
		}
}

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<long long int> v;
        for(int i=0;i<n;i++)
        {
            int value;
            cin>>value;
            v.push_back(value);
        }
        if(m>1)
        {
	        result=0;
	        maxcal(v,n,m-1,result,0);
        }
        else
        {
        	result=INT_MIN;
        	for(int i=0;i<n;i++)
        	{
                if(result<v[i])
                {
                	result=v[i];
                }
        	}
        }
        cout<<result<<endl;
    }
    
    return 0;
}
