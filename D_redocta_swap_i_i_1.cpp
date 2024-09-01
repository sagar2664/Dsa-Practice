#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    
    unordered_map<string,int> ump;
    unordered_map<string,int> dist;
    queue<string> q;
    ump[s]=1;
    dist[s]=0;
    q.push(s);

    while(!q.empty())
    {
        string u=q.front();
        q.pop();

        for(int i=0;i<n-1;i++)
        {
            string v=u;
            swap(v[i],v[i+1]);
            if(ump[v] || dist[v]) continue;
            dist[v]=dist[u]+1;
            ump[v]=1;
            q.push(v);
        }
    }
    cout<<dist["atcoder"]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}