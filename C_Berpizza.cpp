#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int q;
    cin>>q;

    vector<int> m;
    set<int> t;
    set<pair<int,int>> c;

    while(q--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int x;
            cin>>x;
            m.push_back(x);
            t.insert((int)m.size()-1);
            c.insert({~x,(int)m.size()-1});
        }
        else
        {
            int i=(op==2?*t.begin():c.begin()->second);
            cout<<i+1<<' ';
            t.erase(i);
            c.erase({~m[i],i});
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}