#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    while(cin>>n && n){
        int sum= 0, ans = 0 ,num[n] ;
        for(int i=0 ;i<n ;i++){
            int a ;
            cin>>a ;
            num[i] = a ;
        }

        sort(num,num+n) ;

        for(int i=0 ;i<n ;i++){
            sum = sum+num[i] ;
            ans+=sum ;
        }
        cout<<ans-num[0]<<endl ;
    }
    return 0 ;
}
