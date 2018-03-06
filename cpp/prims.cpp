#include<bits/stdc++.h>

using namespace std ;

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
    for(int i=1 ;i<=8 ;i++){
        cost[i] = 5555 ;
        parent[i] = 0 ;
        tree[i] = false ;
    }

    cost[1] = -1 ;
    cost[1] = 0 ;
}


void prims()
{
    initialize() ;

    again:

        int u = extractMin() ;
        for(int i=1 ;i<=8 ;i++){
            if(graph[u][i] && graph[u][i]<cost[i]){
                parent[i] = u ;
                cost[i] = graph[u][i] ;
            }
        }

        tree[u] = true ;

        for(int i=1 ;i<9 ;i++){
            if(tree[i]==false){
                goto again ;
            }
        }
}


int main()
{
    cout<<"source destination cost" <<endl ;
    for(int i=0 ;i<16 ;i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        graph[u][v] = w ;
        graph[v][u] = w ;
    }

    prims() ;

    int sum = 0 ;
    for(int i=1 ;i<9 ;i++){
        if(cost[i]<1234){
            sum+=cost[i] ;
        }
    }
    cout<<"ans :: "<<sum<<endl ;
    return 0 ;
}
