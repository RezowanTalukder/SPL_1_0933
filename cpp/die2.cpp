#include<bits/stdc++.h>

using namespace std ;

int main()
{
    string str ;
    string ans="" ;
    cin>>str ;
    int l = str.length() ;
    int c1=0,c2=0,c0=0 ;
    for(int i=0 ;i<l ;i++){
        if(str[i]==0)c0=1 ;

    }

    return 0 ;
}

/*

string cur="" ;
        if(str[i]!='2')cur+=str[i] ;
        if(str[i]=='2'){
            sort(cur,cur+cur.length()) ;
            ans+=cur ;
            cur="" ;
            for(int j=i+1;j<l ;j++){
                if(str[j]=='1'){
                    ans+='1' ;
                }
                if(str[i]=='0'){
                    ans+='2' ;
                    break ;
                }
                if(str[i]=='2'){

                }
            }
        }

*/
