#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,m,k ;
    cin>>n>>m>>k ;
    if(k<=n){
        cout<<k+1<<" "<<"1"<<endl ;
        return 0 ;
    }
    else
    {
        int a,b ;
        k-=(n-1) ;
        a = n-1 ;


        int x = k/(m-1) ;
        int r = k%(m-1) ;

        a = a-x ;

        if(x%2){
            if(r==0){
              a++ ;
              b = 1 ;
            }
           else  b = m-1-r ;
        }

        else{
            if(r==0){
              a++ ;
              b = r ;
            }
            else b = r ;
        }

        /*
        a = a-x ;

        if(r)a-- ;



        if(x%2){
            b = m-r ;
        }
        else b = r ;
        */

        cout<<a+1<<" "<<b+1<<endl ;

    }

    return 0 ;
}

