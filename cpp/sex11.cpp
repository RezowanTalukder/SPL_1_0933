#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int a[1000] ;

    memset(a,0,sizeof(a)) ;

    a['a'] = 100 ;
    a['e'] = 100 ;
    a['i'] = 100 ;
    a['o'] = 100 ;
    a['u'] = 100 ;
    a['n'] = 100 ;

    string str ;

    cin>>str ;

    int l = str.length() ;

    if(a[str[l-1]]!=100){
        cout<<"NO" ;
        return 0 ;
    }
    int f = 0 ;
    for(int i=0 ;i<l-1 ;i++){
        if(a[str[i]]==100){
            //cout<<"here "<<str[i]<<endl ;
        }
        else {
            if(a[str[i+1]]!=100){
                cout<<"NO" ;
                return 0 ;
            }
        }
    }
    cout<<"YES" ;

    return 0 ;
}
