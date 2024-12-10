#include <bits/stdc++.h>
using namespace std;
#define ll long long
// int gcd(int a, int b)
// {
//     while (b)
//     {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
// int lcm(int a, int b)
// {
//     return a / gcd(a, b) * b;
// }

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll nb = 0;
    ll ans = 0;
    string s;
    cin >> s;
    int i = 0;
    while (i < n)
    {
        int cnt = 0;
        while (i < n && s[i] == '0' && cnt < m)
        {
            cnt++;
            i++;
        }
        if (cnt > 0)
        {
            i--; 
        }
        if (cnt == m)
        {
            ans++;
            i += k;
        }
        else
        {
            i++;
        }
    }

    cout << ans << endl;
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
