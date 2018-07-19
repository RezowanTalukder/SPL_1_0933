#include<bits/stdc++.h>

using namespace std ;



int main()
{
    int s ,j = 0 ;
    string str ;
    cin>>s ;
    int arr[s/2] ;
    for(int i=1 ;i<=s/2;i++){
        if(s%i==0)arr[j++] = i ;
    }
    arr[j] = s ;
    cin>>str ;
    for(int i=0 ;i<=j ;i++){
        int pos = arr[i] ;
        char ch ;
        for(int ii=0,j=pos-1 ;ii<pos/2 ;ii++,j--){
            ch = str[ii] ;
            str[ii] = str[j] ;
            str[j] = ch ;
        }
    }

    cout<<str<<endl ;
}
