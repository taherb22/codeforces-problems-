#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll k;
    cin >> k;

    cout << min(n, k) * min(m, k) << endl;
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
