#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

string key_generation(string key_mode, vector<string> roles)
{
    vector<string> rw = {"read_settings", "read_intent", "write_settings", "create_intent", "confirm_intent"};
    vector<string> re = {"read_settings", "read_intent"};
    vector<string> w = {"write_settings", "create_intent", "confirm_intent"};
    vector<string> p = {"update_dispute", "create_dispute", "read_dispute", "create_refund", "cancel_refund", "read_refund"};
    vector<string> ro = {"banking", "identity", "climate", "capital"};

    vector<string> ans;
    for (int r = 0; r < roles.size(); r++)
    {
        if (roles[r] == "payments")
        {
            for (int j = 0; j < rw.size(); j++)
                ans.push_back(roles[r] + "." + rw[j]);
            for (int j = 0; j < p.size(); j++)
                ans.push_back(roles[r] + "." + p[j]);
        }
        else if (roles[r] == "admin")
        {
            for (int j = 0; j < ro.size(); j++)
            {
                for (int k = 0; k < rw.size(); k++)
                    ans.push_back(ro[j] + "." + rw[k]);
            }
        }
        else if (roles[r] == "admin_readonly")
        {
            for (int j = 0; j < ro.size(); j++)
            {
                for (int k = 0; k < re.size(); k++)
                    ans.push_back(ro[j] + "." + re[k]);
            }
        }
        else
        {
            for (int k = 0; k < rw.size(); k++)
                ans.push_back(roles[r] + "." + rw[k]);
        }
    }
    sort(ans.begin(), ans.end());

    if (key_mode == "permissions")
    {
        string s;
        for (auto it : ans)
            s += it, s += " ";
        return s;
    }

    vector<string> allr;
    for (int i = 0; i < ro.size(); i++)
    {
        for (int j = 0; j < rw.size(); j++)
            allr.push_back(ro[i] + "." + rw[j]);
    }
    for (int j = 0; j < rw.size(); j++)
        allr.push_back("payments." + rw[j]);
    for (int j = 0; j < p.size(); j++)
        allr.push_back("payments." + p[j]);

    sort(allr.begin(), allr.end());

    map<string,int> mp;
    for(int i=0;i<allr.size();i++)
    {
        mp[allr[i]]=i;
    }

    int b=0;
    for(int i=0;i<ans.size();i++)
    {
        b=b|(1<<mp[ans[i]]);
    }

    string s;
    while(b)
    {
        s+=to_string(b%2);
        b/=2;
    }
    while(s.size()<31)
    s+="0";

    return s;
}

void solve()
{
    string ans=key_generation("blah",{"admin_readonly","payments"});
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}