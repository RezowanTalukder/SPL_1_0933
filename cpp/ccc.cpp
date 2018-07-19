#include<iostream>

using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    int arr[n] ;

    for(int i=0 ;i<n ;i++)cin>>arr[i] ;

    int sum1=0,sum2=0 ,ans = 0 ;

    sum1+=arr[0];
    sum2+=arr[n-1] ;

    int cur ;

    if(n%2==1){

        for(int i=1,j=n-2 ;i!=j; ){
            if(sum1==sum2){
                if(sum1>ans){
                    ans = sum1 ;
                }
                sum1+=arr[i] ;
                i++ ;
                sum2+=arr[j] ;
                j-- ;
            }
            else if(sum1>sum2){
                sum2+=arr[j] ;
                j-- ;
            }
            else {
                sum1+=arr[i] ;
                i++ ;
            }

            cur = i ;
        }



        if(sum1>sum2){
            sum2+=arr[cur] ;
        }
        else sum1+=arr[cur] ;

        if(sum1==sum2){
                if(sum1>ans)ans = sum1 ;
            }

        cout<<ans<<endl ;

    }

    else{
        for(int i=1,j=n-2 ;i!=j; ){
            if(sum1==sum2){
                if(sum1>ans){
                    ans = sum1 ;
                }
                sum1+=arr[i] ;
                i++ ;
                sum2+=arr[j] ;
                j-- ;
            }
            else if(sum1>sum2){
                sum2+=arr[j] ;
                j-- ;
            }
            else {
                sum1+=arr[i] ;
                i++ ;
            }
        }
        cout<<ans<<endl ;

    }

     return 0 ;
}
