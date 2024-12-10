#include <bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    ll nb = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
       
    }
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
