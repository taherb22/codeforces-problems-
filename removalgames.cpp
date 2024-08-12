#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n ;
    cin>> n; 
    ll a[n] ; vector<ll> b(n) ; 
    for(int i=0 ;i<n; i++){
        cin>>a[i] ;
    }
    for(int i=0 ; i<n ;i++){
        cin>>b[i] ; 
    }
    int t1=0 ; 
    for(int i=0 ; i<n ;i++){
        if(a[i]!=b[i]){
            t1=1 ;
            break ; 
        }
    }
    if(!t1){
       cout<<"Bob"<<endl ; 
       return ; 
    }
    reverse(b.begin() ,b.end()) ; 
     t1=0 ; 
    for(int i=0 ; i<n ;i++){
        if(a[i]!=b[i]){
            t1=1 ;
            break ; 
        }
    }
    if(!t1){
       cout<<"Bob"<<endl ; 
    }
    else{
        cout<<"Alice"<<endl ; 
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
