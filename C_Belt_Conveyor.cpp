#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(auto &i:g) cin>>i;

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=true;

    map<char,pair<int,int>> mp;
    mp['R']={0,1};
    mp['L']={0,-1};
    mp['U']={-1,0};
    mp['D']={1,0};

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        int i=x+mp[g[x][y]].first;
        int j=y+mp[g[x][y]].second;

        if(i<0 || j<0 || i>=n || j>=m)
        {
            cout<<x+1<<' '<<y+1<<endl;
            return;
        }
        else if(vis[i][j])
        {
            cout<<-1<<endl;
            return;
        }

        q.push({i,j});
        vis[i][j]=true;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}