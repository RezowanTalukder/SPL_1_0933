#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    pair<int,int>pi ;
    pair<pair<int,int>,int>pii ;
    cin>>n ;
    vector< pair<pair<int,int>,int> >V ;
    for(int i=1 ;i<=n ;i++)
    {
        int a,b ;
        cin>>a>>b ;
        V.push_back(make_pair(make_pair(a,b),i));
    }

    sort(V.begin(),V.end()) ;


    for(int i=0 ;i<V.size()-1 ;i++){
        for(int j = i+1 ;j<V.size() ;j++){
            if(V[j].first.second<=V[i].first.second){
                cout<<V[j].second<<" "<<V[i].second<<endl ;
                return 0 ;
            }
        }
    }
    cout<<"-1 -1"<<endl ;
    return 0 ;
}

