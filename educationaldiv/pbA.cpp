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
