#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

vector<int> v;
int rec(int l,int r)
{
    int len=(r-l+1);
    if(l>=r || len<=5) return 0;

    

    int ans;
    int m=(l+r)/2;
    if(len&1)
    {
        ans=m+rec(l,m-1)+rec(m+1,r);
        v.push_back(m);
    }
    else ans=rec(l,m)+rec(m+1,r);

    return ans;
}

void solve()
{
    for(int i=1;i<=100;i++)
    {
        v.clear();
        cout<<i<<' '<<rec(1,i)<<endl;
        sort(v.begin(),v.end());
        for(auto it:v)
        cout<<it<<' ';
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin >> _t;while (_t--)
        solve();
}