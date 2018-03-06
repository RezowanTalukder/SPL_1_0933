#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;

    while(cin>>n && n)
    {
        bool node[n] ;

        map<int , vector<int> >mp ;
        int x ,y ;
        cin>>x ;
        while(cin>>y && y){
            mp[x].push_back(y) ;
        }
        int num ,start ;
        cin>>num ;
        while(num--)
        {
            memset(node,false , sizeof(node)) ;
            cin>>start ;
            queue<int>Q ;
            Q.push(start) ;
            int v = Q.front() ; Q.pop() ;
            while(!Q.empty())
            {
                for(int u = 1 ;u<=mp[v].size() ;u++){
                if(!mp[v][u]){
                    node[u] = true ;
                    Q.push(u) ;
                    }
                }

            }
            int cont = 0 ;
            for(int i=1 ;i<=n ; i++){
                    if(!node[i])cont++ ;
            }
            cout<<cont<<endl ;
        }
    }
    return 0 ;
}
