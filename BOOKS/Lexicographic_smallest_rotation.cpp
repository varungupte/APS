// https://blog.csdn.net/Interstellar_/article/details/77553828

// uvaonlinejudge 2755 - Hidden Password



#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<iostream>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define fin freopen("a.txt","r",stdin)
#define fout freopen("a.txt","w",stdout)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
const int inf = 1e9 + 10;
const int maxnode = 4e5 + 10;
const int sigma_size = 26;
const int maxn = 1e5 + 10;
char s[maxn*2];
int n;

int solve()
{
    int i = 0, j = 1, k = 0;
    while(i < n/2 && j < n/2)
    {
        if(k == n/2) return i;
        if(s[i+k] == s[j+k]) k++;
        else if(s[i+k] < s[j+k]) { j += k+1; k = 0; }
        else
        {
            i += k+1;
            
            if(i > j) swap(i, j);
            if(i == j) j++;
            k = 0;
        }
    }
    return i;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%s", &n, s);
        for(int i = n; i <= n*2-1; i++)
            s[i] = s[i-n];
        n *= 2;
        printf("%d\n", solve());
    }
    return 0;
}

