#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,k ;
    cin>>n>>k ;
    int arr[n],arr1[n] ;
    for(int i=0 ;i<n ;i++){
        cin>>arr[i] ;
    }
    for(int i=0 ;i<n ;i++){
        cin>>arr1[i] ;
    }


    int temp = 0 ,index ;

    for(int i=0 ;i<n-k+1 ;i++){
        if(arr1[i]==0){
            int sum = 0 ;
            for(int j=i ;j<i+k ;j++){
                sum+=arr[j] ;
            }

            if(temp<sum){
                    temp = sum ;
                    index = i ;
            }
        }
    }

    long long ans = 0 ;

    for(int i=0 ;i<index ;i++){
        if(arr1[i]==1)ans+=arr[i] ;
    }
    for(int i=index ;i<index+k ;i++){
        ans+=arr[i] ;
    }

    for(int i=index+k ;i<n ;i++){
        if(arr1[i]==1)ans+=arr[i] ;
    }

    cout<<ans<<endl  ;

    return 0 ;
}

