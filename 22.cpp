#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt += (s[i] == '1');
    }

    if (cnt == 1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}