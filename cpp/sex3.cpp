#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,*arr ;
    cin>>n ;
    arr = new int[n] ;

    for(int i=0 ;i<n ;i++)cin>>arr[i] ;

    sort(arr,arr+n,greater<int>()) ;

    int ans = 0,s = 0 ;
    bool save = false ;

    for(int i=0 ;i<n-1 ;i++){

        if((arr[i]-arr[i+1])>0){
                ans++ ;
                //cout<<"$";
            }
        else if(save==false){
            save = true ;
            s = arr[i] ;
        }
        else {
            int cur = arr[i] ;
            if(s>cur){
                ans++ ;
               // cout<<"^";
                save = false ;
            }

        }
    }

    cout<<ans<<endl ;

    return 0 ;
}
