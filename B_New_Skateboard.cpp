#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
string s;
void solve()
{
    cin >> s;
    n = s.length();
    int p=5;
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        int cur=s[i]-'0';
        if(cur%4==0) ans++;
        int t=cur*10+p;
        if(t%4==0) ans+=i+1;
        p=cur;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}