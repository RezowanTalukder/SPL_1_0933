#include <bits/stdc++.h>

using namespace std ;

int main()
{

	freopen("in.txt","r",stdin) ;

	int n ;
	cin>>n ;

	int arr[n+1][n+2] ;
	for(int i=0 ;i<n+2 ;i++){
		arr[0][i] = 0 ;
	}
	for(int i=0 ;i<n+1 ;i++){
		arr[i][0] = 1e5 ;
		arr[i][n+1] = 1e5 ;
	}

	for(int i=1 ;i<n+1 ;i++){
		for(int j=1 ;j<n+1 ;j++){
			cin>>arr[i][j] ;
		}
	}

	for(int i=2 ;i<n+1 ;i++){
		for(int j=1 ;j<n+1 ;j++){

            int pre = arr[i][j] ;
			arr[i][j] = min(arr[i-1][j-1],arr[i-1][j]) ;
			arr[i][j] = pre+ min(arr[i][j],arr[i-1][j+1]) ;
			cout<<arr[i][j]<<"  " ;

		}
		cout<<endl ; ;
	}

	int ans = 1e5 ;

	for(int i=1 ;i<n+1 ;i++){
		ans = min(ans,arr[n][i]) ;
	}

	cout<<ans<<endl ;

	return 0 ;
}
