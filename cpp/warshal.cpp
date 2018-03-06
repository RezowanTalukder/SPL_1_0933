#include<bits/stdc++.h>

using namespace std ;
#define N 10
int graph[10][10] ;
int cost[10] ;
int parent[10] ;
bool tree[10] ;



void initialize()
{
    memset(graph,0,sizeof(graph)) ;
    for(int i=1 ;i<=5 ;i++){
        cost[i] = 5555 ;
        tree[i] = false ;
    }
    cost[1] = 0 ;
}


