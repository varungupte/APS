/*All combinations of strings that can be used to dial a number
Given a number, print all possible combinations of strings that can be used to dial the given number in a phone with following specifications.

In the given phone, we can dial,
2 using A or B or C,
3 using D or E or F,
……………….
8 using T or U or V,
9 using W or X or Y or Z,
1 using only 1
0 using 0.

For example if 23, is the given phone number, the program should print AD, AE, AF, BD, BE, BF, CD, CE, CF
*/

#include <bits/stdc++.h> 
using namespace std; 
void call(string ss,map<char,string> m,int n,string &s)
{
    if(n==ss.size())
    {
        cout<<s<<endl;
        return ;
    }
    string p=m[ss[n]];
    // cout<<
    
    for(int i=0;i<p.size();i++)
    {
        s=s+p[i];    
        call(ss,m,n+1,s);   
        s.erase(n);
    }
}
int main () 
{ 
    map<char,string> m;char a='a';int count=0,k=2;
    m['2']="abc";
    m['3']="def";
    m['4']="ghi";
    m['5']="jkl";
    m['6']="mno";
    m['7']="pqrs";
    m['8']="tuv";
    m['9']="wxyz";
    m['0']="0";
    m['1']="1";
    string ss;
    cin>>ss;
    string s="";
    call(ss,m,0,s);
    return 0; 
} 
