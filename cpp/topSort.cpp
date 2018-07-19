#include<bits/stdc++.h>

using namespace std ;

int mp[10][10] ,vert ;

struct top{
    int topSortNo ;
    int inDegree ;
}vertex[10];

void topSort()
{
    queue<int>Q ;
    int counter = 0 ;

    while(!Q.empty())Q.pop() ;

    for(int v=1 ;v<=vert ;v++){
        if(vertex[v].inDegree==0){
            Q.push(v) ;
        }
    }
    while(!Q.empty())
    {
        int currentVertex = Q.front() ; Q.pop() ;

        vertex[currentVertex].topSortNo = ++counter ;

        for(int v = 1 ;v<=vert ;v++){
            if(mp[currentVertex][v] && --vertex[v].inDegree==0){
                Q.push(v) ;
            }
        }
    }
    if(counter!=vert)cout<<"did not worked" <<endl ;
    else {
        for(int i=1 ;i<=vert ;i++){
            cout<<i<<"  "<<vertex[i].topSortNo<<endl ;
        }
    }
}

int main()
{
    int m,n ;
    cin>>vert ;
    for(int i=1;i<=vert;i++ ){
        cin>>n>>m ;
        mp[n][m] = 1 ;
        vertex[m].inDegree++ ;
    }
    topSort() ;
    return 0 ;
}
