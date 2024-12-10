#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
   ll n;
   cin >> n;
   vector<ll> v[n];
   for (int i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      while (x--)
      {
         ll y;
         cin >> y;
         v[i].push_back(y);
      }
   }
   vector<ll> ans;
   for (auto mm : v[0])
   {
      int b = 0;
      for (int i = 1; i < n; i++)
      {
         for (auto mm1 : v[i])
         {
            if (mm == mm1)
            {
               b = 1;
            }
         }
      }
      if (b == 1)
      {
         ans.push_back(mm);
      }
   }
   for (auto mm : ans)
   {
      cout << mm << " ";
   }
   cout << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   // cin >> t;
   while (t--)
   {
      solve();
   }

   return 0;
}
