#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , ans = 0  ;
    string str ;
    cin>>n ;
    cin>>str ;
    int curX= 0 , curY = 0 ,curRegion = 0 ;

    if(str[0]=='U'){
            curRegion = 1 ;
            curX = curX ;
            curY = curY+1 ;
    }
    else {
            curRegion =0 ;
            curX = curX+1 ;
            curY = curY ;
    }

    int reg ;

    for(int i=1 ;i<str.length() ;i++){
        if(str[i]=='U'){
            curX = curX ;
            curY = curY+1 ;
        }
        if(str[i]=='R'){
            curX = curX+1 ;
            curY = curY ;
        }

        if(curX>curY){
            reg = 0 ;
            if(abs(reg-curRegion)==1){
                ans++ ;
                curRegion=0 ;
            }
        }

        if(curX<curY){
            reg = 1 ;
            if(abs(reg-curRegion)==1){
                ans++ ;
                curRegion=1 ;
            }
        }
    }
    cout<<ans<<endl ;
}
