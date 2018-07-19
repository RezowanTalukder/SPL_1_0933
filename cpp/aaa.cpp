#include<iostream>

using namespace std ;
typedef long long ll ;


int main()
{
    ll n ;
    cin>>n ;
    //ll arr[n] ;
    for(ll i=0 ; i<n ;i++){
        ll x ;
        cin>>x ;
        if(x%2==1)cout<<x<<" " ;
        else cout<<x-1<<" ";
    }
    cout<<endl ;
    return 0 ;
}
