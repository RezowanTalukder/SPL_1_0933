#include<bits/stdc++.h>

using namespace std ;

int main()
{

    int n,a=1e9,b=1e9,cur ,flag = 1 ;
    cur = max(a,b) ;
    cin>>n ;
    while(n--){
        int x,y ;
        cin>>x>>y ;
        int m = max(x,y) ;
        int l = min(x,y) ;

        if(cur<l)flag = 0 ;

        if(m<cur)cur = m ;
        else cur = l ;

    }

    if(flag)cout<<"YES" ;
    else cout<<"NO" ;

    return 0 ;
}
