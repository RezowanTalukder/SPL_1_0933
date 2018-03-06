#include<bits/stdc++.h>

using namespace std ;
int graph[10][10] ;
int arr[10][10] ;
int cur;
bool visited[10] ;

int func(int a)
{
    int x= 0,el = 0 , cur=a ;
    for(int i =1 ;i<9 ;i++){
        if(graph[cur][i]==1 && !visited[i]){

            visited[i] = true ;
            arr[cur][x] =  i ;
            x++ ;
            el++ ;
        }
    }
    cout<<cur<<"  :: " ;
    for(int i=0 ;i<el ;i++){
        cout<<arr[cur][i]<<"  " ;
    }
    cout<<endl ;
    return el ;
}

int main()
{
    freopen("in.txt","r",stdin) ;

    memset(graph,0,sizeof(graph)) ;
    memset(visited,false,sizeof(visited)) ;

    for(int i=1 ;i<9 ;i++){
        int u,v ;
        cin>>u>>v ;
        graph[u][v] = 1 ;
        graph[v][u] = 1 ;

    }


/*
    for(int i=1 ;i<8 ;i++){
        for(int j=1 ;j<8 ;j++){
            cout<<graph[i][j]<<"  " ;
        }
        cout<<endl ;
    }
*/


    int a ;
    cin>>a ;
    int el =func(a) ;

    for(int i=0 ;i<el ;i++){
        int y = func(arr[a][i]) ;
    }

    return 0 ;
}


