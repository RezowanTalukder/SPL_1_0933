#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int m,n ;

    cin>>n>>m ;

     int arr[n+2] ;
     memset(arr,0,sizeof arr) ;

    for(int i=0 ;i<m ;i++){
        int x ;
        cin>>x ;
        arr[x]++ ;
    }

    int temp = 10004 ;
    for(int i=1 ;i<=n ;i++){
        if(arr[i]<temp)temp = arr[i];
    }
    cout<<temp ;

    return 0 ;
}
