#include<bits/stdc++.h>

using namespace std ;
#define N 10
int graph[10][10] ;
int cost[10] ;
int parent[10] ;
bool tree[10] ;
vector<int>V[20] ;


void initialize()
{

    for(int i=1 ;i<=5 ;i++){
        cost[i] = 5555 ;
    }
}


void dijkas()
{
    cost[1] = 0 ;
    for(int u=1 ;u<=N ;u++){
        for(int v=1 ;v<=N ;v++){
            if(graph[u][v] && cost[u]+graph[u][v]<cost[v]){
                cost[v] = cost[u]+graph[u][v] ;
            }
        }
    }

    cout<<"......................"<<endl ;


    for(int i=0 ;i<5 ;i++){
        if(cost[i+1]>100)cout<<"unreachable"<<endl ;
        else {
            V[i+1].push_back(cost[i+1]) ;
        }
    }
}

int main()
{
    freopen("iit.txt","r",stdin) ;
    memset(graph,0,sizeof(graph)) ;
    cout<<"source----destination---cost" <<endl ;
    for(int i=0 ;i<10 ;i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        graph[u][v] = w ;
    }
    initialize() ;
    for(int i=1 ;i<5 ;i++){
        dijkas() ;
    }

    bool bel[10] ;
    memset(bel,false,sizeof(bel)) ;

    for(int i=1 ;i<=5 ;i++){
        cout<<"node "<<i<<" :" ;
        int x = V[i][0] ;
        //cout<<"X here "<<x;
        for(int j= 0 ;j<V[i].size() ;++j){
            cout<<V[i][j]<<"  " ;
            if(x!=V[i][j]){
                bel[i] = true ;
            }
        }
        cout<<endl ;
    }
    cout<<"\n\n\n" ;
    for(int i=1 ;i<=5 ;i++){
        if(bel[i])cout<<"more relaxation possible in : "<<i<<endl ;
    }
    return 0 ;
}


