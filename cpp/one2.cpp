#include<bits/stdc++.h>

using namespace std ;

int main()
{
    string str1,str2 ;
    cin>>str1>>str2 ;
    int l1 = str1.length() ;
    int l2 = str2.length() ;
    int mil = 0 ;
    for(int i = l1-1,j=l2-1 ;i>=0 && j>=0 ;i--,j--){
        if(str1[i]!=str2[j]){
            break ;
        }
        else mil++ ;
    }

    int ans = (l1-mil)+(l2-mil) ;
    cout<<ans<<endl ;

    return 0 ;
}

