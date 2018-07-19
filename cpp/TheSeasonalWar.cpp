#include<bits/stdc++.h>
using namespace std ;

int visited[25][25] ;
vector<string>V ;
pair<int,int>P ;
int n , ans , I, J ;
int xi[8] = {1,1,0,-1,-1,-1,0,1} ;
int yi[8] = {0,1,1,1,0,-1,-1,-1} ;

void visit(int a , int b)
{
    ans++ ;
    stack< pair<int,int> >S ;
    S.push(make_pair(a,b)) ;
    while(!S.empty())
    {
        P = S.top() ; S.pop() ;
        visited[P.first][P.second] = 1 ;

        for(int i= 0 ;i<8 ;i++){
            I = P.first + xi[i] ;
            J = P.second + yi[i] ;
            if(I>=0 && J>=0 && I<=n &&J<=n && !visited[I][J]){
                S.push(make_pair(I,J)) ;
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin) ;
    freopen("out.txt","w",stdout) ;

    string s ;
    int caseNo = 1 ;

    while(cin>>n)
    {
        V.clear() ;
        for(int i=0 ;i<n ;i++){
            cin>>s ;
            V.push_back(s) ;
        }

        memset(visited,0,sizeof(visited)) ;

        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<n ;j++){
                if(V[i][j]=='0')visited[i][j] = 1 ;
            }
        }

        ans  = 0 ;

        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<n ;j++){
                if(V[i][j]=='1' && !visited[i][j]){
                    visit(i,j) ;
                }
            }
        }
        cout<<"Image number "<<caseNo<<" contains "<<ans<<" war eagles."<<endl ;
    }
}
