#include<bits/stdc++.h>

using namespace std ;

int main()
{
    string str ;
    char a[6] = {'a','e','i','o','u','n'} ;
    cin>>str ;

    for(int i=0 ;i<str.length()-1 ; i++){
        for(int j= 0 ; j<6 ;j++){
        char ch = str[i] ;
        if(ch==a[j])break;

        else{
                int flag = 0 ;
                for(int k=0 ;k<6; k++){
                    char c = str[i+1] ;
                    if(c==a[k]){
                        flag = 1 ;
                    }
                }
            if(flag==0){
                cout<<" age NO"<<endl ;
                return 0 ;
            }
            }
        }
    }
    int f = 0 ;
    for(int i=0 ;i<6 ;i++){
        if(str[str.length()-1]==a[i]){
            f = 1 ;
        }
    }

    if(f==0)cout<<"NO" ;
    else cout<<"YES" ;

    return 0 ;

}
