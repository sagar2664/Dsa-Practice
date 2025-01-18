#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

class uf
{
public:
    vector<int> rank;
    vector<int> par;

    uf(int n)
    {
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i, rank[i] = 0;
    }

    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int u, int v)
    {
        int ru = find(u);
        int rv = find(v);

        if (rank[ru] < rank[rv])
            swap(ru, rv);

        rank[ru] += rank[rv];
        par[rv] = ru;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    uf myuf(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        myuf.unite(u,v);
    }

    set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(myuf.find(i));
    }

    cout<<(int)st.size()-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}