#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,m ;
    cin>>n>>m ;
    int c[n],a[m] ;
    for(int i=0 ;i<n ;i++)cin>>c[i] ;
    for(int i=0 ;i<m ;i++)cin>>a[i] ;
    int ans = 0 ;
    for(int i=0,j=0 ;i<n&&j<m ;){
        //if(i==m)break ;
        if(c[i]>a[j]){
            i++ ;
        }
        else {
            ans++ ;
            i++;
            j++ ;
        }
    }
    cout<<ans<<endl ;
    return 0 ;
}
