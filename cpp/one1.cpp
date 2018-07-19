#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,*arr ;
    cin>>n ;
    arr = new int[n] ;
    for(int i=0 ;i<n ;i++){
        //int a ;
        cin>>arr[i] ;

    }
    int sum = 0 ;
    int ans[1001] ;
    int j=0 ;
    for(int i=0 ;i<n-1 ;i++){

        if(arr[i+1]-arr[i]!=1){
            sum++ ;
            ans[j++] = arr[i] ;
        }

    }
    sum++ ;
    ans[j] = arr[n-1] ;
    cout<<sum<<endl ;
    for(int i=0 ;i<=j ;i++){
        cout<<ans[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}

