#include<bits/stdc++.h>

using namespace std ;

typedef long long LL ;

int main()
{
    LL n,m,w ;
    cin>>n>>w>>m ;

    string str[n+5] ;
    LL value[n+5] ;

    map<string,LL>P ;

    for(LL i=1 ;i<=n ;i++){
        cin>>str[i] ;
    }

    for(LL i=1 ;i<=n ;i++){
        cin>>value[i] ;
    }

    for(LL i=0 ;i<w ;i++){
        LL x  ;
        cin>>x ;
        LL y,r[x+4] ,temp = 1000000005 ;

        for(LL j=0 ;j<x ;j++){
              cin>>y ;
              r[j] = y ;
              if(value[y]<temp){
                 temp = value[y] ;
              }
        }

        for(int j=0 ;j<x ;j++){
            value[r[j]]  = temp ;
        }
    }

    for(LL i=1 ;i<n+1 ;i++){
        P[str[i]] = value[i] ;
    }

    LL sum = 0 ;

    for(LL i=0 ;i<m ;i++){
        string s ;
        cin>>s ;
        sum+=P[s] ;

    }

    cout<<sum <<endl ;
    return 0 ;
}

