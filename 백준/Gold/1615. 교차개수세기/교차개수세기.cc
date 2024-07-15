#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

pii ar[2000 * (2000 - 1) / 2 + 1];
ll fenwick[2001];

void add(int pos, int val)
{
  while (pos <= m)
  {
    fenwick[pos] += val;
    pos += (pos & -pos);
  }
}

ll sum(int pos)
{
  ll ret = 0;

  while (pos)
  {
    ret += fenwick[pos];
    pos &= (pos - 1);
  }

  return ret;
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;

  for (int i = 0; i < m; ++i)
    cin >> ar[i].first >> ar[i].second;
  
  sort(ar, ar + m);

  ll res = 0;

  for (int i = m - 1; i >= 0; --i)
  {
    res += sum(ar[i].second - 1);
    add(ar[i].second, 1);
  }

  cout << res;
}