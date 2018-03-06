#include<bits/stdc++.h>

using namespace std ;

int graph[100][100] ;
int cost[100] ;
int parent[100] ;
bool tree[100] ;
int N,m,T ;
int s,d ;
queue<int>Q ;
int edge[100] ;

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
    for(int i=0 ;i<=98 ;i++){
        cost[i] = 10005 ;
        tree[i] = false ;
        edge[i] = 0 ;
    }

}

void printPath(int s,int d)
{
    if(parent[d]==-1){
            cout<<" "<<d ;
            return ;
    }

    printPath(s,parent[d]) ;
    cout<<" "<<d ;

}

void dijkas(int s)
{
    cost[s] = 0 ;
    parent[s] = -1 ;
    Q.push(s) ;
    while(!Q.empty()){
            int u=Q.front() ;Q.pop() ;
                for(int v=0 ;v<=N ;v++){
                    if(graph[u][v] && cost[v]>cost[u]+graph[u][v]){
                        cost[v] = cost[u]+graph[u][v] ;
                        parent[v] = u ;
                        Q.push(v) ;
                    }
            }
    }
}

int main()
{
    //freopen("huh.txt","r",stdin) ;

    int cases ;
    cin>>cases ;
    for(int i=1 ;i<=cases;i++){
            initialize() ;
            while(!Q.empty())Q.pop() ;
            cin>>N;
            for(int i=1 ;i<=N ;i++){
                int v, w ,n ;
                cin>>n ;
                while(n--){
                    cin>>v>>w ;
                    graph[i][v] = w ;
                }
            }
            cin>>s>>d ;
            T=d ;
            dijkas(s) ;

            cout<<"Case "<<i<<": Path = " ;

            printPath(s,d) ;

            cout<<"; " ;

            cout<<cost[d]<<" second delay"<<endl ;

            while(!Q.empty())Q.pop() ;
    }



    return 0 ;
}



