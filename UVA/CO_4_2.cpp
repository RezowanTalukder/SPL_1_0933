#include<bits/stdc++.h>

using namespace std ;

typedef pair<int,int>pii  ;
typedef pair< int,pii >pip ;

int nodes,edges,weight ,test , cas = 1 ;
bool *node , *parent ;
int adj[100][100] ;

int main()
{
    cin>>test ;
    for(int t = 1 ;t<test+1 ;t++)
    {
        cin>>nodes>>edges ;

        vector< pip >V ;

        node = new bool[nodes+2] ;
        parent = new bool[nodes+2] ;
        for(int i=1 ;i<=nodes ;i++){
            node[i] = false ;
            parent[i] = false ;
        }

        memset(adj,0,sizeof adj) ;

        for(int i=0 ;i<edges ;i++){
            int a,b,c ;
            cin>>a>>b>>c ;
            V.push_back(make_pair(c,make_pair(a,b))) ;
            adj[a][b] = 1 ;
        }

        sort(V.begin(),V.end()) ;

        int totalCost = 0 ,flag = 1 ;
        cout<<"Case #"<<t<<" : " ;

        for(int i=0 ;i<V.size();i++){
            int from = V[i].second.first ;
            int to = V[i].second.second ;

            if(parent[to] == false ){
                parent[from] = true ;
                parent[to] = true ;
                node[from] = node[to] = true ;
                totalCost+=V[i].first ;
            }
            for(int j=1 ;j<=nodes ;j++){
                if(node[j]==false){
                        flag = 0 ;
                        break ;
                }
            }
            if(flag==1 && i==V.size()-1){
                cout<<"No second way"<<endl ;
                break ;
            }
            if(flag==1 && i<V.size()-1){
                cout<<"Second way costs : "<<totalCost<<endl;
            }
        }
        if(!flag)cout<<"No way"<<endl ;

    }
    return 0 ;
}
