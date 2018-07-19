#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,k ;
    cin>>n>>k ;
    string str[n] ;
    for(int i=0 ; i<n ;i++){
        cin>>str[i] ;
    }

    int ansRow=1,ansCol=1 ;

    int _max = 0 ;

    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<n ;j++){
            int temp = 0 ,flag = 0 ;
            if(str[i][j]=='.'){
                if(i+k<n){
                    for(int x = i ;x<i+k ;x++){
                        if(str[i][x]!='.')break ;
                        else flag++ ;
                    }
                    if(flag==k-1){
                        temp++ ;
                    }
                    flag = 0 ;
                }
                if(i-k>=0){
                    for(int x = i ; x>i-k ;x--){
                        if(str[i][x]!='.')break ;
                        else flag++ ;
                    }
                    if(flag==k-1){
                        temp++ ;
                    }
                    flag = 0 ;
                }
                //////////

                if(j+k<n){
                    for(int x = i ;x<j+k ;x++){
                        if(str[x][j]!='.')break ;
                        else flag++ ;
                    }
                    if(flag==k-1){
                        temp++ ;
                    }
                    flag = 0 ;
                }
                if(i-k>=0){
                    for(int x = i ; x>i-k ;x--){
                        if(str[i][x]!='.')break ;
                        else flag++ ;
                    }
                    if(flag==k-1){
                        temp++ ;
                    }
                    flag = 0 ;
                }
            }
        }
    }

    return 0 ;
}
