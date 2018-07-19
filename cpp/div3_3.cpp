#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main()
{
    ll n,k ;
    cin>>n>>k ;
    ll arr[n] ;
    for(ll i=0 ;i<n ;i++){
        cin>>arr[i] ;
    }
    sort(arr,arr+n) ;
    if(n==k){
            cout<<arr[n-1]<<endl ;
            return 0 ;
    }

    ll ans ;
    ll x = arr[k-1] ;
    ll y = arr[k] ;
    if(x==y)ans = -1 ;
    else ans = x ;

    cout<<ans<<endl ;

    return 0 ;
}


