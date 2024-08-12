#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ld, ld>> v;
    for (int i = 0; i < n; i++)
    {
        ld x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    ld xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    ld distance = sqrt((ys - yt) * (ys - yt) + (xt - xs) * (xt - xs));
    // cout << distance << endl;
    for (auto [x, y] : v)
    {

        ld d = sqrt((yt - y) * (yt - y) + (xt - x) * (xt - x));
        // cout << d << endl;
        if (d <= distance)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
