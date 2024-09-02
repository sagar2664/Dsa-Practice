#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
string s;
vector<vector<int>> dp;
set<int> st;

int rec(int i, int p)
{
    if (i == n)
        return 0;

    if (dp[i][p] != -1)
        return dp[i][p];

    int ans = 0;
    int num = s[i] - '0';
    if (p != 0)
        num = 10 * (s[i - 1] - '0') + (s[i] - '0');
    if (st.find(num) != st.end())
        ans = 1 + rec(i + 1, 0) + rec(i + 1, 1);
    else
        ans = rec(i + 1, 0) + rec(i + 1, 1);
    
    return dp[i][p]=ans;
}
void solve()
{
    cin >> s;
    n = s.length();
    for(int i=0;i<100;i++)
    {
        if(i%4==0) st.insert(i);
    }
    dp.resize(n+1,vector<int>(2,-1));
    cout<<rec(0,0)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}