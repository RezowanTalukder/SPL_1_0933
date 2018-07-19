#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<string ,string>P ;
    vector< pair<string ,string> >V ;

    int n , m ;
    cin>>n>>m ;
    for(int i=0 ;i<n ;i++){
        string s , ip ;
        cin>>s ;
        cin>>ip ;
        V.push_back(make_pair(s,ip)) ;
    }
    for(int i=0 ;i<m ;i++){
        string s ,ip,ip_pre ;
        cin>>s ;
        cin>>ip_pre ;

        ip = ip_pre.substr(0, ip_pre.size()-1);

        for(int it = 0 ;it< V.size() ; it++){
            if(V[it].second == ip){
                cout<<s<<" "<<ip<<"; #"<<V[it].first<<endl ;
            }
        }
    }
    return 0;
}
