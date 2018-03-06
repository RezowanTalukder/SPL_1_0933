#include<bits/stdc++.h>

using namespace std ;
#define N 10
int graph[10][10] ;
int cost[10] ;
int parent[10] ;
bool tree[10] ;



int extractMin()
{
    int temp = 10000 ,minNode ;

    for(int i=1 ;i<=8 ;i++){
        if(! tree[i] && cost[i]<temp){
            minNode = i ;
            temp = cost[i] ;
        }
    }
    return minNode ;
}

void initialize()
{
    memset(graph,0,sizeof(graph)) ;
    for(int i=1 ;i<=5 ;i++){
        cost[i] = 5555 ;
        tree[i] = false ;
    }
    cost[1] = 0 ;
}

void dijkas()
{
    for(int u=1 ;u<=N ;u++){
        for(int v=1 ;v<=N ;v++){
            if(graph[u][v] && cost[v]>cost[u]+graph[u][v]){
                cost[v] = cost[u]+graph[u][v] ;
            }
        }
    }
    cout<<"......................"<<endl ;
    for(int i=0 ;i<N ;i++){
        if(cost[i+1]>100)cout<<"unreachable"<<endl ;
        else cout<<cost[i+1]<<endl ;
    }
}

int main()
{
    freopen("dij.txt","r",stdin) ;
    initialize() ;
    cout<<"source----destination---cost" <<endl ;
    for(int i=0 ;i<10 ;i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        graph[u][v] = w ;
    }


    dijkas() ;
    return 0 ;
}

