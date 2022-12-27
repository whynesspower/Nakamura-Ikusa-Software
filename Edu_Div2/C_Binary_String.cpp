#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }
    if (cnt1 == 0 or cnt0 == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = INT_MAX;
    int n = s.size();
    vector<int> post0(n + 1);
    vector<int> post1(n + 1);
    post1[n] = 0;
    post0[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            post1[i] = post1[i + 1] + 1;
        }
        else
        {
            post0[i] = post0[i + 1] + 1;
        }
    }

    int l, r;

    for (int i = 0; i < n; i++)
    {
        l = i;
        for (int j = n - 1; j >= i; j--)
        {
            r = j + 1;
            int aa = post0[r] - post0[l];
            int bb = post1[r] - post1[l];

            ans = min(aa, cnt1 - bb);
        }
    }
    cout << ans << endl;
    return;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}