#include<bits/stdc++.h>
using namespace std ;

int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
int main()
{
    int n ;
    cin >> n;
    for(k=1; k<=n; k++)
    {
        cin >>i>>j;
        cost[i][j]=1 ;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"DFS ORDER OF VISITED VERTICES:";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
   // getch();
    return 0;
}




#include<bits/stdc++.h>

using namespace std ;

DFS_Visit(v)
{
    color[v] = gray ;
    time = time+1 ;
    d[v] = time ;
    low[v] = d[v] ;
    for(int w = 0;w < n && graph[v][w] ; w++){
        if(color[w]==white ){
            prev[w] = v ;
            DFS_Visit(w) ;
            if(low[w]>=d[v]) cout<<"Articulation point : "<<w<<endl ;
            else low[v] = low[w] ;
        }
        else if(prev[v] != w){
            if(d[w]<low[v]) low[v]=d[w] ;
        }
    }
    color[v] = black ;
    time++ ;
    f[v] = d[w] ;
}

int main()
{
    DFS_Visit(start) ;
    return 0 ;
}
