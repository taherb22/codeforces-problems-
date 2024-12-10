#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
    {   
        cin >> a[i];
    }
    ll dp[n][3] ;
    dp[0][0] = 0; dp[0][1]=0 ;
    dp[0][2] = 0; 
    for(int i=1 ; i<n ;i++){
        dp[i][0]=dp[i-1][0]+(a[i]%a[i-1]) ; 
        dp[i][1]=max(dp[i-1][0]+((a[i]+k)%(a[i-1])), dp[i-1][1]+((a[i]+k)%(a[i-1]+k))) ;
        dp[i][2]=max(dp[i-1][2]+a[i]%a[i-1] , dp[i-1][1]+a[i]%(a[i-1]+k) ) ; 
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl; 
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
