#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
vector<ll> graph[N];
bool visited[N];

int bfs(int pos)
{
    ll ans = 0;
    visited[pos] = true;
    queue<int> q;
    q.push(pos);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (graph[x].size() == 1 && visited[graph[x][0]])
        {
            ans++;
        }
        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        graph[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    ll ans = bfs(0);
    if (graph[0].size() == 1)
    {
        ans++;
    }
    if (ans % 2 == 0)
    {
        cout << ans / 2 << endl;
    }
    else
    {
        cout << ans / 2 + 1 << endl;
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
