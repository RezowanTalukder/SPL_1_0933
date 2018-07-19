#include<bits/stdc++.h>

using namespace std ;

int mp[10][10] ;

int main()
{
    memset(mp,0,sizeof(mp)) ;
    int n ,b,a,nodes[10];
    for(int i=0 ;i<10 ;i++)nodes[i] = 0 ;
    cin>>n ;
    while(cin>>a>>b && a &&b)
    {
        mp[a][b] = 1 ;
        mp[b][a] = 1 ;
    }
    int start ;
    cout<<"start vertex: " ;
    cin>>start ;
    queue<int>Q ;
    while(!Q.empty())Q.pop() ;

    Q.push(start) ;

    while(!Q.empty())
    {
        int current = Q.front() ;Q.pop() ;
        for(int i=1 ;i<=n ;i++){
            if(mp[current][i] && !nodes[i]){
                Q.push(i) ;
            }
        }
        nodes[current] = 1 ;
        cout<<"visited:"<<current<<endl ;
    }
    return 0 ;
}
