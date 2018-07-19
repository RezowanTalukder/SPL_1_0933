#include<bits/stdc++.h>

using namespace std;

#define num 10

struct node{
    int from ;
    int to ;
    int cost ;
}node[num];

int temp = 0,temp1 = 0 ,graph[num][num],vertex[num] ;

void prims()
{
    vertex[0] = 1 ;
    int numVertex = num ;
    while(numVertex--)
    {
        int _min = 999 ;
        for(int i=0 ;i<num ;i++){
            if(vertex[i]==1){
                for(int j=0 ;j<num ;j++){
                    if(graph[i][j]>=_min || !graph[i][j]){
                        j++ ;
                    }
                    else if(graph[i][j]<_min){
                        _min = graph[i][j] ;
                        temp = i ;
                        temp1= j ;
                    }
                }
            }
        }
        vertex[temp1] = 1 ;
        node[temp].from = temp ;
        graph[temp][temp1] = 10000 ;
        cout<<temp<<"  "<<temp1<<" cost : "<<_min<<endl ;
    }

}

int main()
{
    memset(graph,0,sizeof(graph)) ;
    memset(vertex,0,sizeof(vertex)) ;

    freopen("inp.txt","r",stdin);

    int edges ;
    cin>>edges ;
    for(int i=0 ;i<edges ;i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        graph[u][v] = w ;
        graph[v][u]  = w ;
    }

    prims() ;

    return 0 ;
}
