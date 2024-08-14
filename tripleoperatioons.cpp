#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
ll precompute[(ll)2e5 + 1];
ll prefixsum[(ll)2e5 + 1];
void solve()
{
    ll l, r;
    cin >> l >> r;

    cout << prefixsum[r] - prefixsum[l - 1] + precompute[l] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    precompute[0] = 0;
    prefixsum[0] = precompute[0];
    for (ll i = 1; i <= 2e5; i++)

    {
        ll k = i;
        while (k != 0)
        {
            precompute[i]++;
            k /= 3;
        }
        prefixsum[i] = precompute[i] + prefixsum[i - 1];
    }

    while (t--)
    {
        solve();
    }

    return 0;
}
