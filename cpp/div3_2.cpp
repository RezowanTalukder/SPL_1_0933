#include<bits/stdc++.h>

using namespace std ;

int main()
{
    map<string ,int>mp ;
    string str ;
    int n ;
    cin>>n ;
    cin>>str ;
    for(int i=0 ;i<n-1 ;i++){
        string s = "" ;
        s+=str[i] ;
        s+=str[i+1] ;
        //cout<<s<<endl ;
        mp[s]++ ;

    }
    int ans = 0 ;
    string bal ;

    for(auto it = mp.begin(); it != mp.end(); ++it )
    {
      int key = it->second;
      string value = it->first ;
      if(key>ans){
        ans = key ;
        bal = value ;
      }
    }

    cout<<bal<<endl ;
    return 0 ;
}

