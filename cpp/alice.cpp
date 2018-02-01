#include<bits/stdc++.h>
using namespace std ;



int main()
{
    string str,ans="",zero_array="" ;
    priority_queue<char>pq ;
    int n ,zero = 0 ;
    cin>>str ;
    n = str.length() ;
    for(int i=0 ;i<n ;i++){
        if(str[i]=='0')zero +=1 ;
        pq.push(str[i]) ;
    }
    if(zero){
        for(int i=0 ;i<=n-zero ;i++){
           ans+=pq.top() ;
           pq.pop() ;
        }

        for(int i= 0 ;i<zero ;i++){
            zero_array+=pq.top() ;pq.pop() ;
        }
        int x = ans.length() ;
        cout<<ans[x-1] ;
        for(int i=zero-1 ; i>=0 ;i--){
            cout<<zero_array[i] ;
        }

        for(int i=x-2 ;i>=0 ;i--){
            cout<<ans[i] ;
        }
    }
    else {
        for(int i=0 ;i<n ;i++){
            ans+=pq.top() ;
            pq.pop() ;
        }
        for(int i=n-1 ;i>=0 ;i--){
            cout<<ans[i] ;
        }
    }
    cout<<endl ;
    return 0 ;
}
/*char x= pq.top() ;pq.pop() ;
        char y = pq.top() ; pq.pop() ;
        cout<<y<<x ;*/
