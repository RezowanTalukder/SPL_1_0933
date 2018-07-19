#include<bits/stdc++.h>

using namespace std ;

int main()
{
    pair<int,int>p ;
    vector< pair<int,int> >v;
    int n,k ;
    cin>>n>>k ;
    for(int i=0 ;i<n ;i++){
        int a ;
        cin>>a ;
        v.push_back(make_pair(a,i)) ;
    }

    sort(v.begin(),v.end()) ;

    int sum=0,j=0 ;
    int arr[k+3],x=0 ;

    for(int i=v.size()-1 ;;i--){
        if(j==k)break ;
        else{
            sum+=v[i].first ;
            arr[x++]=v[i].second ;
        }
        j++ ;
    }
    cout<<sum<<endl ;
    if(k==1){
        cout<<n<<endl ;
        return 0 ;
    }
    sort(arr,arr+k) ;

    for(int i=0 ;i<k ;i++)arr[i]+=1 ;

    cout<<arr[0]<<" ";

    for(int i=0 ;i<k-2 ;i++){
        cout<<arr[i+1]-arr[i]<<" ";
    }
    cout<<n-arr[k-2] ;
    cout<<endl ;
    return 0 ;
}
