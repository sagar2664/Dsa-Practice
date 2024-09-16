#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int a=59049;
    while(a)
    {
        cout<<a%9;
        a/=9;
    }
    cout<<endl;
    a=810;
    while(a)
    {
        cout<<a%9;
        a/=9;
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
}