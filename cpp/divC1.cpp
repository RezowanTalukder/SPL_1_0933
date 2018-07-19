#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,*arr ;
    cin>>n ;
    arr = new int[n] ;

    for(int i=0 ;i<n ;i++)cin>>arr[i] ;

    sort(arr,arr+n) ;

    int ans = 0 ,temp = 0 ;

    for(int i=0 ;i<n-1 ;i++){
        if((arr[i+1]-arr[i])==0)temp++ ;
        else {
            if(ans<temp)ans = temp ;
            //cout<<ans<<endl ;
            temp = 0 ;
        }
    }
    if(ans<temp)ans = temp ;

    cout<<ans+1<<endl ;
    return 0 ;
}
