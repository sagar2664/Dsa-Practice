#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

string largestMagical(string binString)
{
    string s=binString;

    vector<string> v;
    int n=s.length();

    int i=0;
    while(i<n)
    {
        int j=i;
        int cnt=0;
        while(j<n && s[j]=='1')
        {
            cnt++;
            j++;
        }
        if(j==n) break;
        int t=cnt;
        while(t-- && j<n)
        {
            if(s[j]=='1') break;
            j++;
        }
        if(j==n && t!=0) break;
        
        if((j!=n && s[j]=='1') || j==n)
        {
            v.push_back(s.substr(i,2*cnt));
        }
        else
        {
            
        }

    }
}
void solve()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}