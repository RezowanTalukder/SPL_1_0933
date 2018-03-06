#include<bits/stdc++.h>

using namespace std ;

typedef pair<int,int>pii ;

int parent[100] ;

vector< pair<int,pii> > V ;
vector< pair<int,pii> > V1 ;
vector< pair<int,pii> > T ;

int findSet(int i)
{
    if(i==parent[i])  return i ;
    else return findSet(parent[i]) ;
}

void union_set(int u , int v)
{
    parent[v] = u ;
}

void cruskal()
{
    int uP,vP;

    for(int i=0 ;i<V.size() ;++i){
        uP = findSet((V[i].second).first) ;
        vP = findSet((V[i].second).second) ;
        if(uP!=vP){
            T.push_back(V[i]) ;
            union_set(uP,vP) ;
        }
    }
    int ans = 0 ;
    for(int i =0 ;i<T.size() ;++i){
        //cout<<T[i].second.first<<" "<<T[i].second.second<<" "<<T[i].first<<endl ;
        ans+=T[i].first ;
    }
    cout<<ans<<endl  ;

}

void second()
{
    for(int i=0 ;i<100 ;i++) parent[i] = i ;

    int k ;
    cin>>k ;
    while(k--)
    {
        int u,v,w ;
        cin>>u>>v>>w ;
        V1.push_back(make_pair(w,pii(u,v))) ;
    }


    T.clear() ;
    V.clear() ;

    for(int i=0 ;i<V1.size() ;++i){
        V.push_back(V1[i]) ;
    }

    sort(V.begin(),V.end()) ;


    cruskal() ;

    int ini ;

    while(ini--){
        int u,v,w ;
        cin>>u>>v>>w ;
    }

}

int main()
{

    freopen("in.txt","r",stdin) ;

    int edges ;
    cin>>edges ;
    edges-- ;
    while(edges--)
    {
        int u,v,w ;
        cin>>u>>v>>w ;
        V.push_back(make_pair(w,pii(u,v))) ;
        V1.push_back(make_pair(w,pii(u,v))) ;
    }

    sort(V.begin(),V.end()) ;

    for(int i=0 ;i<100 ;i++) parent[i] = i ;

    cruskal() ;

    second() ;


    return 0 ;
}

