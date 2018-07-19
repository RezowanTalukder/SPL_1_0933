#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    string str,ans ;
    cin>>n ;
    cin>>str ;
    n-- ;
    ans = str ;
    int x = 1 ;
    while(n--)
    {
        cin>>str ;
        for(int i=0 ;i<str.length() ;i++){
            char ch = str[i] ;
            int flag = 0 ;
            for(int j = 0 ;j<ans.length() ;j++){
                if(ch==ans[j]){
                        flag = 1 ;
                }
            }
            if(flag==0){
                    x++ ;
                    ans+=ch ;
            }
        }
    }
    cout<<x<<endl ;
    return 0 ;
}
