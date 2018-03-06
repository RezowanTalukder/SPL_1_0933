#include<bits/stdc++.h>

using namespace std ;

typedef pair<int,int>pii ;

int parent[100] ;

vector< pair<int,pii> > V ;
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
    int uP,vP ;
    bool forest = false ;
    int arr[100] ;
    int x = 0 ;

    for(int i=0 ;i<V.size() ;++i){
        uP = findSet((V[i].second).first) ;
        vP = findSet((V[i].second).second) ;
        if(uP==vP){
           // cout<<V[i].first<<" " ;
            arr[x] = V[i].first ;
            x++ ;
            forest = true ;
        }

        if(uP!=vP){
            T.push_back(V[i]) ;
            union_set(uP,vP) ;
        }

    }
    sort(arr,arr+x) ;

    /*
    int ans = 0 ;
    for(int i =0 ;i<T.size() ;++i){
        cout<<T[i].second.first<<" "<<T[i].second.second<<" "<<T[i].first<<endl ;
        ans+=T[i].first ;
    }
    cout<<ans<<endl  ;
    */
    if(!forest)cout<<"forest" ;
    else {
        for(int i=0 ;i<x ;i++){
            cout<<arr[i]<<" " ;
        }
    }

    cout<<endl ;
}


int main()
{

    //freopen("in.txt","r",stdin) ;

    int edges ,nodes ,cas = 1;
    while(cin>>nodes>>edges && nodes && edges)
    {
        while(edges--)
        {
            int u,v,w ;
            cin>>u>>v>>w ;
            V.push_back(make_pair(w,pii(u,v))) ;
        }

        sort(V.begin(),V.end()) ;

        for(int i=0 ;i<100 ;i++) parent[i] = i ;

        cruskal() ;

        V.clear() ;
        T.clear() ;
    }

    return 0 ;
}
