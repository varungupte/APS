#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, vector<vector<int>> &ans, int i, int j)
{
    // if (i < 0 || j >= arr.size())
    // {
    //     return 0;
    // }
    // if (ans[i][j] != -1)
    //     return ans[i][j];
    if(j == i)
        return arr[i];
    if (j == i+1)
    {
        ans[i][j] = max(arr[i], arr[j]);
        return ans[i][j];
    }
    int temp = max(arr[i] + min(solve(arr, ans, i+2, j), solve(arr, ans, i+1, j-1)),
                   arr[j] + min(solve(arr, ans, i+1, j-1), solve(arr, ans, i, j-2)));
    ans[i][j] = temp;
    return ans[i][j];
}

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; int temp;
        cin >> n;
        vector<int> arr(n);
        vector<vector<int>> ans(n,vector<int>(n,0));
        for (int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        int res=solve(arr, ans, 0, n-1);
        cout << res << endl;
    }
}



// F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//                    Vj + min(F(i+1, j-1), F(i, j-2) )) 