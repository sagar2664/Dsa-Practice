#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'
#define i64 long long

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> st;
    int s=0;

    auto bexp = [&](i64 a, i64 r) {
      i64 res = 1;
      for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
      return res;
    };

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int y=0;
        while(!(x&1)){x/=2;y++;}
        
        while(!st.empty())
        {
            int u=st.back().first;
            int v=st.back().second;

            //int val=(u*bexp(2,v))%mod;
            //int cur=(x*(1LL<<y))%mod;

            if(y>=30 || u<=(x<<y))
            {
                s=(s+u)%mod;
                y+=v;
                st.pop_back();
            }
            else
            break;
        }

        if(y>0) st.push_back({x,y});
        else
        s=(s+x)%mod;

        int res=s;
        for(auto it:st) res=(res+(bexp(2,it.second)*it.first)%mod)%mod;
        //cout<<x<<' '<<y<<' ';
        cout<<res<<' ';
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}