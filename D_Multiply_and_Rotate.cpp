#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int a,x;
    cin>>a>>x;

    int level=0;
    queue<int> q;

    int m=1;
    while(m<=x)
    m*=10;

    vector<int> dist(m,-1);
    q.push(1);
    dist[1]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int du=dist[u];
        int l=a*u;
        if(l<m && dist[l]==-1)
        q.push(l),dist[l]=du+1;

        if(u>=10 && u%10!=0)
        {
            string s=to_string(u);
            char c=s.back();
            s.pop_back();
            s=c+s;
            int r=stoi(s);
            if(r<m && dist[r]==-1)
            q.push(r),dist[r]=du+1;
        }
    }
    cout<<dist[x]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}