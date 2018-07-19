#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

bool power(ll n)
{
   return (ceil(log2(n)) == floor(log2(n)));
}

/*
bool power(ll n)
{
    for(ll i=0 ; ;i++){
        if(pow(2,i)==n)return true ;
        if(pow(2,i)>n)break ;
    }

    return false ;
}
*/

int main()
{
    ll *nn ,n ;
    bool *num ;
    cin>>n ;
    nn = new ll[n] ;
    num = new bool[n] ;

    for(ll i=0 ;i<n ;i++){
        cin>>nn[i] ;
        num[i] = false ;
    }

    sort(nn,nn+n) ;

    ll rem = 0 ;

    for(ll i=0 ;i<n && num[i]==false ;i++){
        for(ll j=0 ;j<n && i!=j ;j++){

            if(num[i]==true && nn[i]==nn[j]){
                num[j] = true ;
                break ;
            }

            else if(power(nn[i]+nn[j])){
                num[i] = true ;
                num[j] = true ;
                break ;
            }

        }
    }

    for(ll i=0 ;i<n ;i++){
        if(num[i]==false){
            //cout<<nn[i]<<endl  ;
            rem++ ;
        }
    }

    cout<<rem<<endl ;

    return 0 ;
}
