#include<bits/stdc++.h>

using namespace std ;

struct node{
    int u,v,w ;
}node[10];

int id[10] ,n ;
bool visited[10] ;

findBap(int x)
{
    if(id[x]!=x)return findBap(id[x]) ;
    return id[x] ;
}

int kruskal()
{
    int Totalcost = 0 ;
    for(int i=0 ;i<10 ;i++){
        id[i] = i ;
    }
    for(int i=0 ;i<n ;i++){
        int p = node[i].u ;
        int q= node[i].v ;
        if(p!=q && !visited[i]){
            Totalcost+=node[i].w ;
            id[p] = q ;
        }
    }
}

int main()
{
    int testCase ;
    memset(visited,false ,sizeof(visited)) ;

    cin>>testCase ;
    while(testCase--)
    {
        int i=0 ;
        cin>>n ;
        if(n==0)break ;
        while(n--)
        {
            int x,y,c ;
            cin>>u>>v>>w ;
            node[i].u = x ;
            node[i].v = y ;
            node[i].w = c ;
            i++ ;
        }
    }

    return 0 ;
}
