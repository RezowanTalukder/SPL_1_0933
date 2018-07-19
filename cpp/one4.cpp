#include<bits/stdc++.h>

using namespace std ;

int n,m ,*arr ;
vector<int>V ;

bool median(int l,int r)
{
    sort(V.begin(),arr.begin()+r,arr.end()) ;

}

int main()
{

    cin>>n>>m ;
    //arr = new int[n] ;
    int index ,ar ;
    for(int i=0 ;i<n ;i++){
        cin>>ar ;
        V.push_back(ar) ;
        if(m==arr[i])index = i+1 ;
    }

    int ans = 0 ;

    for(int i=index ,j = index ; ;i++,j--){
        if(median(i,j))ans++ ;
        if(i<n && median(i+1,j))ans++ ;
        if(j>=0 && median(i,j-1))ans++ ;


    }


}
