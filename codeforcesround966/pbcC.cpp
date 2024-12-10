#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    int a[n];
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    ll pref_occ[n];
    mp[a[0]]++;
    pref_occ[0] = mp[a[0]] % 2;
    for (int i = 1; i < n; i++)
    {
        mp[a[i]]++;
        pref_occ[i] = (mp[a[i]] % 2) | pref_occ[i - 1];
    }
    for (auto mm : pref_occ)
    {
        cout << mm << " ";
    }
    cout << endl;

    while (q--)
    {
        int l;
        cin >> l;
        int r;
        cin >> r;
        l--;
        r--;
        if (l == 0)
        {
            if (pref_occ[r] > 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            if (pref_occ[r] - pref_occ[l - 1] > 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
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
