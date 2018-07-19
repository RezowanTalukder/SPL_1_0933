#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,m ;
    cin>>n>>m ;
    int arr[n] ;
    for(int i=0 ;i<n ;i++){
        cin>>arr[i] ;
    }
    int ans = 0,curr ;

    for(int i=0 ;i<n ;i++){
        if(arr[i]<=m){
                ans++ ;
                //cout<<arr[i]<<endl ;
                curr = i ;
        }
        else break ;
    }
    for(int i=n-1 ;i>curr ;i--){
        if(arr[i]<=m){
                ans++ ;
                //cout<<arr[i]<<endl ;
        }
        else break ;
    }
    cout<<ans<<endl ;
    return 0 ;
}
