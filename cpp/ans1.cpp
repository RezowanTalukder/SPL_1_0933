#include<bits/stdc++.h>

using namespace std ;

int main()
{
    queue<int>q[2] ;
    int n ;
    cin>>n ;
    while(n){
        for(int i=1 ;i<=n ;i++){
            q[0].push(i) ;
        }
        int qn = 0 ;
        for(int m=2 ;m<10 ; m++){
            int last_poped , pr ;
            q[qn].pop() ;
            for(int i=0 ;i<m-1 ;i++){
                q[1-qn].push(q[qn].front()) ;
                last_poped = q[qn].front() ;
                q[qn].pop() ;
                pr++ ;

                if(q[qn].empty()){

                    if(q[1-qn].empty()){
                        if(last_poped == 13){
                            cout<<m<<endl ;
                            return 0 ;
                        }

                    }
                    int bakiM = m-1-pr ;
                    qn = 1-qn ;
                    for(int j = 0 ;j<bakiM ;j++){
                        q[qn].push(q[1-qn].front()) ;
                        q[1-qn].pop() ;
                    }
                }

            }
        }
        cin>>n ;
    }
    return 0 ;
}
