#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int testCase = 1 , r ;
    while(cin>>r && r){
        while(r--){
            int x,sec = 0 ;
            queue<int>Q[r] ;
            queue<int>secQ ;
            map<int,int>mp ;
            while(cin>>x){

                for(int i=0 ;i<x ;i++){
                    int data ;
                    cin>>data ;
                    mp[data]= sec ;
                }
                sec++ ;
            }

            string str ;

            int num ;
            cout<<"Scenario #"<<testCase++<<endl ;

            while(cin>>str && str[0]!='S'){
                if(str[0]=='E'){
                    cin>>num ;
                    Q[mp[num]].push(num) ;

                    if(!secQ.find(mp[num])){
                        secQ.push(mp[num]) ;
                    }
                }
                else {
                    if(!secQ.empty()){
                        int a = secQ.front() ;
                        cout<<Q[a].front()<<endl ;
                        Q[a].pop() ;

                        if(Q[a].empty()){
                            secQ.pop() ;
                        }
                    }
                }
            }
        }
    }

    return 0 ;
}
