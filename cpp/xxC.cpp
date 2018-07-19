#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,m ;
    cin>>n>>m ;
    int arr[n],arr2[n],arrow[m] ;
    for(int i=0 ;i<n ;i++){
        cin>>arr[i] ;
        arr2[i] = arr[i] ;
    }
    for(int i=0 ;i<m ;i++){
        cin>>arrow[i] ;
    }
    int dead ;
    for(int i=0 ;i<m ;i++){
        int c = arrow[i] ;
        for(int j = 0 ;j<n ;j++){
            c-=arr[j] ;
            if(c<=0){
                dead=j+1 ;
            }
            if()
        }
    }
}
