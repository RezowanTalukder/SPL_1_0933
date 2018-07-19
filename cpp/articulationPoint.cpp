#include<bits/stdc++.h>

using namespace std ;
void dfs(int start);
int mp[10][10] ;
int node ,counter = 0 ;

struct vertex{
    bool visited ;
    int parent ;
    int low ;
    int num ;
}vertex[10];

void artiKutta(int start)
{
    vertex[start].low  = vertex[start].num ;
    for(int i=1 ;i<=node && mp[start][i] ;i++){
        if(vertex[i].num>vertex[start].num){
            dfs(vertex[i]) ;
            if(vertex[i].low>=vertex[start].num){
                cout<<start<<"  is a articulation point"<<endl ;
            }
            vertex[start].low = min(vertex[start].low,vertex[i].low) ;
        }
        else {
            if(vertex[start].parent!=vertex[i]){
                vertex[start].low = min(vertex[start].low,vertex[i].num) ;
            }
        }
    }

}

void dfs(int start)
{
    start.num = counter++ ;
    start.visited = true ;
    for(int i=1;i<=node && mp[start][i] ;i++){
        if(i.visited==false){
            i.parent = start ;
            dfs(i) ;
        }
    }
}

int main()
{
    cin>>node ;
    memset(mp,0,sizeof(mp)) ;
    int b,a ;
    for(int i=0 ;i<10 ;i++){
            vertex[i].visited = false ;
    }
    while(cin>>a>>b && a &&b)
    {
        mp[a][b] = 1 ;
        mp[b][a] = 1 ;
    }
    int start ;
    cout<<"start from::" ;
    cin>>start ;
    artiKutta(start) ;
    return 0 ;
}
