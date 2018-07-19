#include<bits/stdc++.h>

using namespace std ;

int main()
{
    string str ;
    int n,m ;
    bool *use ;
    cin>>n>>m ;
    use = new bool[n] ;
    for(int i=0 ;i<n ;i++){
        use[i] = true ;
    }
    cin>>str ;
    string word = str ;

    sort(word.begin(), word.end());

    //cout<<word<<endl ;

    /*
    string removed_word = "" ;

    for(int i=0 ;i<m ;i++){
        removed_word+=word[i] ;
    }
    */

    for(int i=0 ;i<m ;i++){
        int a ;
        if(word[i]==word[i+1])a = i ;
        else a = 0 ;
        for(int j=a ;j<n ;j++){
            if(str[j]==word[i] && use[j]){
                use[j] = false ;
                break ;
            }
        }
    }

    for(int i=0 ;i<n ;i++){
        if(use[i]==true){
            cout<<str[i] ;
        }
    }
    cout<<endl ;

    return 0 ;
}
