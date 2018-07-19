#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ,one = 0,zero = 0;
    string str ;
    cin>>n ;
    cin>>str ;
    for(int i=0 ;i<n ;i++){
        if(str[i]=='0')zero++ ;
        else one++ ;
    }

    if(one)cout<<"1" ;
    for(int i=0 ;i<zero;i++){
        cout<<"0" ;
    }
    cout<<endl ;
    return 0 ;
}
