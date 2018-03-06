#include<bits/stdc++.h>

using namespace std ;

int graph[100][100] ;
int cost[100] ;
int parent[100] ;
bool tree[100] ;
int N,m ;
queue<int>Q ;

int extractMin()
{
    int temp = 10000 ,minNode ;

    for(int i=0 ;i<=N ;i++){
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
    for(int i=0 ;i<=N ;i++){
        cost[i] = 10005 ;
        tree[i] = false ;
    }

}

void dijkas(int s)
{
    cost[s] = 0 ;
    Q.push(s) ;
    while(!Q.empty()){
            int u=Q.front() ;Q.pop() ;
                for(int v=0 ;v<=m ;v++){
                    if(graph[u][v] && cost[v]>cost[u]+graph[u][v]){
                        cost[v] = cost[u]+graph[u][v] ;
                        Q.push(v) ;
                    }
            }
    }
}

int main()
{
    freopen("54.txt","r",stdin) ;

    int cases ;
    cin>>cases ;
    for(int i=1 ;i<=cases;i++){

            while(!Q.empty())Q.pop() ;

            int s,d ;
            cin>>N>>m>>s>>d ;
            initialize() ;
            for(int i=0 ;i<m ;i++){
                int u,v,w ;
                cin>>u>>v>>w ;
                graph[u][v] = w ;
                graph[v][u] = w ;
            }
            dijkas(s) ;
            cout<<"Case #"<<i<<": " ;
            if(cost[d]>1000)cout<<"unreachable"<<endl ;
            else cout<<cost[d]<<endl ;
            while(!Q.empty())Q.pop() ;
    }



    return 0 ;
}


