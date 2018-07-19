#include<bits/stdc++.h>

using namespace std ;

typedef pair<int, int> pii ;
typedef pair<int, pii> pip ;

bool a[10] ;
int b[10] ;

int main()
{
    vector< pip >V ;
    memset(a,63,sizeof(a)) ;
    memset(b,63,sizeof(b)) ;
    for(int i=0 ;i<10 ;i++){
        cout<<a[i]<<"  "<<b[i]<<endl ;
    }
    int a,u,v ;
    //cin>>a>>u>>v ;
    V.push_back(pip(a,pii(u,v))) ;
//    cout<<V.begin().pip.second().second() <<endl ;
    return 0 ;
}
