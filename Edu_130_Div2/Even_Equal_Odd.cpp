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
// #define mp make_pair
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

ll getFirstSetBitPos(ll n)
{
    return log2(n & -n);
}

void solve()
{
    map<ll, ll> mp;
    ll n;
    cin >> n;
    ll arr[2 * n];
    ll noEven = 0, noOdd = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            noOdd++;
        }
        else
        {
            noEven++;
            ll temp = getFirstSetBitPos(arr[i]);
            mp[temp]++;
        }
    }

    if (noEven == noOdd)
    {
        cout << 0 << endl;
        return;
    }
    else if (noEven < noOdd)
    {
        cout << (noOdd - n) << endl;
        return;
    }
    else
    {
        ll target = noEven - n;
        ll count = 0;
        ll ans = 0;
        auto it = mp.begin();
        while (count != target and it != mp.end())
        {
            if (count + it->second <= target)
            {
                ans += (it->first * it->second);
                count += it->second;
                if (count == target)
                    break;
            }
            else
            {
                ll temp2 = count + it->second;
                ll temp3 = temp2 - target;
                ll temp4 = it->second - temp3;
                ans += (temp4 * it->first);
                break;
            }
            it++;
        }
        cout << ans << endl;
        return;
    }
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