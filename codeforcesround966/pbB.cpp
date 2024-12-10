#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    string output = "";
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        string ch = "";
        for (int i = 0; i < mid; i++)
        {
            ch += '0';
        }
        cout << "? " << ch << endl;
        cout.flush();
        int c;
        cin >> c;
        if (c == 0)
        {
            r = mid - 1;
            ans = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    if (ans == -1)
    {
        string output = "";
        for (int i = 0; i < n; i++)
        {
            output += "1";
        }
        cout << "! " << output << endl;
        cout.flush();
        return;
    }
    // cout << ans << endl;
    // cout << oth << endl;

    for (int i = 0; i < ans; i++)
    {
        if (ans > oth)
        {
            output += '0';
        }
        else
        {
            output += '1';
        }
    }
    while (output.size() < n)
    {
        cout << "? " << output + "0" << endl;
        cout.flush();
        int c;
        cin >> c;
        if (c == 1)
        {
            output += "0";
        }
        else
        {
            cout << "? " << output + "1" << endl;
            cout.flush();
            int c;
            cin >> c;
            if (c == 1)
            {
                output += "1";
            }
            else
            {
                break;
            }
        }
    }
    while (output.size() < n)
    {
        cout << "? 0" + output << endl;
        cout.flush();
        int c;
        cin >> c;
        if (c == 1)
        {
            output = "0" + output;
        }
        else
        {

            output = "1" + output;
        }
    }
    cout << "! " << output << endl;
    cout.flush();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
