#include<bits/stdc++.h>

using namespace std ;

int mp[100][100] ;
bool visited[100] ;
int ans = 0 ;
int test ,n,m ,a,b ;

void dfs(int start)
{
        visited[start] = true ;
        for(int j=1 ;j<=n ;j++){
            if(visited[j]==false && mp[start][j]){
                    visited[j] ;
                    dfs(j) ;
            }
        }
}

int main()
{

    memset(mp,0,sizeof(mp)) ;
    memset(visited , false , sizeof(visited)) ;

    cin>>test ;
    while(test--)
    {
        int start ;
        cin>>n>>m ;
        for(int i=0 ;i<m ;i++){
            cin>>a>>b ;
            mp[a][b] = 1 ;
            if(i==0)start = a ;
        }

        dfs(start) ;
        ans++ ;

        for(int i=1 ;i<=n ;i++){
            if(visited[i]==false){
                dfs(i) ;
                ans++ ;
            }
        }
        cout<<ans<<endl ;
        ans=0 ;
    }

    return 0 ;
}
