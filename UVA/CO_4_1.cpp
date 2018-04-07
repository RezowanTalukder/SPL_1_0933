#include<bits/stdc++.h>

using namespace std ;

typedef pair<int,int>pii  ;
typedef pair< int,pii >pip ;

int nodes,edges,weight ,test , cas = 1 ;
bool *node ;
int adj[100][100] ;

bool possible(int src ,int dest,int nodes)
{
     for(int i=0 ;i<nodes ;i++){
        if(adj[src][i] && node[i]==true){
            if(i==dest)return true ;
            else {
                    possible(i,dest,nodes) ;

            }
        }
     }

     node[src]  = false ;

     return false ;
}

int main()
{

    while((cin>>nodes>>edges>>test) && nodes && edges && test)
    {
        memset(adj,0,sizeof adj) ;

        vector< pip >V ;
        node = new bool[nodes] ;

        for(int i=0 ;i<nodes ;i++){
            node[i] = false ;
        }

        for(int i=0 ;i<edges ;i++){
            int a,b,c ;
            cin>>a>>b>>c ;
            adj[a][b] = adj[b][a] = 1 ;
            V.push_back(make_pair(c,make_pair(a,b))) ;
        }

        int sor , dest ;
        sort(V.begin(),V.end()) ;
        cout<<"Case No: "<<cas++ <<endl ;
        for(int t =0 ;t<test ;t++){
            cin>>sor >>dest ;

            for(int i=0 ;i<edges ;i++){
                for(int j = 0 ;j<=i ;j++){
                    int f = V[j].second.first ;
                    int l = V[j].second.second ;
                    node[f] = true ;
                    node[l] = true ;
                }

                if(possible(sor,dest,nodes)){
                        cout<<(V[i].first)<<endl ;
                }
            }

        }

    }
    return 0 ;
}
