#include <bits/stdc++.h>
using namespace std;

// Function to shift characters backwards using prime numbers
char sb(char ch, int s) {
  return 'A' + (ch - 'A' - s + 26) % 26;
}

// Reverse Substring Shift: Move the first n characters to the end
string rss(string& s, int n) {
  return s.substr(n) + s.substr(0, n);
}

// Reverse Insert Characters: Remove inserted character 'c' after every 'm' characters
string ric(string &s, char c, int m) {
  string res;
  int cnt = 0;
  for (char ch : s) {
    if (cnt == m) {
      if (ch == c) {
        cnt = 0;
        continue;
      }
    }
    res += ch;
    cnt++;
    if (cnt > m) cnt = 0;
  }
  return res;
}

// Reverse Character Duplication: Remove extra duplicate characters
string rd(string& s, int d) {
  string res;
  for (size_t i = 0; i < s.size(); i += d) {
    res += s[i];
  }
  return res;
}

// Reverse Custom Mapping: Reverse the custom substitution using 'smap'
string rs(string& s, string& smap) {
  unordered_map<char, char> rsmap;
  for (int i = 0; i < smap.size(); i++) {
    rsmap[smap[i]] = 'A' + i;
  }
  string res;
  for (char ch : s) {
    res += rsmap[ch];
  }
  return res;
}

// Reverse Prime Number Shift: Shift characters backwards by the corresponding prime number
string rps(string& s) {
  vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  string res;
  for (size_t i = 0; i < s.size(); i++) {
    res += sb(s[i], p[i % p.size()]);
  }
  return res;
}

void solution() {
  string es;
  cin >> es;
  string smap;
  cin >> smap;
  int d;
  cin >> d;
  char c;
  cin >> c;
  int m, n;
  cin >> m >> n;
  
  // Decrypting in reverse order of encryption
  string s = rss(es, n);       // Level 5 -> Level 4
  s = ric(s, c, m);            // Level 4 -> Level 3
  s = rd(s, d);                // Level 3 -> Level 2
  s = rs(s, smap);             // Level 2 -> Level 1
  string ans = rps(s);         // Level 1 -> Original
  
  cout << ans << endl;
}

int main() {
  solution();
  return 0;
}
