#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int k,n,s,p ;
    cin>>k>>n>>s>>p ;
    int a,b ;
    (n%s)?a=(n/s)+1:a=(n/s) ;
    ((k*a)%p)?b=((k*a)/p+1):b=((k*a)/p) ;

    cout<<b<<endl ;
    return 0 ;
}
