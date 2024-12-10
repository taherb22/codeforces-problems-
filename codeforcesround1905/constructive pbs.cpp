#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;

int h[N];
vector<pair<ll, ll>> a(N);
vector<pair<ll, ll>> tree[4 * N];
int n;

vector<pair<ll, ll>> mrg(vector<pair<ll, ll>> &x, vector<pair<ll, ll>> &y)
{
    vector<pair<ll, ll>> ans;
    int i = 0, j = 0;

    while (i < x.size() && j < y.size())
    {
        if (x[i].first < y[j].first)
        {
            ans.push_back(x[i]);
            i++;
        }
        else
        {
            ans.push_back(y[j]);
            j++;
        }
    }
    while (i < x.size())
    {
        ans.push_back(x[i]);
        i++;
    }
    while (j < y.size())
    {
        ans.push_back(y[j]);
        j++;
    }
    return ans;
}

void build(int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns == ne)
    {
        tree[id] = {{a[ns].first, a[ns].second}};
        return;
    }

    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;

    build(l, ns, md);
    build(r, md + 1, ne);

    tree[id] = mrg(tree[l], tree[r]);
}

pair<ll, ll> query(int id, int ns, int ne, int k)
{
    auto &ans = tree[id];

    // Use lower_bound with custom comparator to compare the `first` element
    auto it = lower_bound(ans.begin(), ans.end(), make_pair(k, 0LL),
                          [](const pair<ll, ll> &a, const pair<ll, ll> &b)
                          {
                              if (a.first == b.first)
                              {
                                  return a.second < b.second;
                              }
                              return a.first < b.first;
                          });

    if (it == ans.end())
    {
        return {0, 0}; // If nothing is found, return 0
    }
    return {it - ans.begin(), it->second}; // Return the index of the found element
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > pos || pos > ne)
    {
        return;
    }
    if (ns == ne)
    {
        tree[id] = {{val, pos}};
        return;
    }

    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    upd(pos, val, l, ns, md);
    upd(pos, val, r, md + 1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

void solve()
{
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        a[i] = {h[i], i};
    }

    build(0, 0, n - 1); // Properly initialize the segment tree

    int r[m];
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
    }
    for (auto mm : tree[0])
    {
        cout << mm.first << " " << mm.second << endl;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        if (i == 1)
        {
            for (auto mm : tree[0])
            {
                cout << mm.first << " " << mm.second << endl;
            }
            cout << endl;
        }

        pair<ll, ll> x = query(0, 0, n - 1, r[i]);
        cout << x.second + 1 << endl;
        cout << x.first << endl;
        upd(x.first, tree[0][x.first].first - r[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
