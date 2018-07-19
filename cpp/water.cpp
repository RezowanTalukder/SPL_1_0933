#include <bits/stdc++.h>

using namespace std ;

typedef float in ;

bool rever(in a,in b)
{
	return a>b ;
}

int main()
{

	in n,A,B ;
	cin>>n>>A>>B ;

	list<in>L ;
	list<in>::iterator it1 ;

	//list<int>::reverse_iterator it ;

	in sum = 0 ;
	in r = n-1 ;
	while(n--){
		in x ;
		cin>>x ;
		sum+=x ;
		L.push_back(x) ;
	}

	

	in s1 = L.front() ;
	//sum-=s1 ;
	//cout<<s1<<endl ;
	L.remove(L.front()) ;

	L.sort(rever) ;

	in ans = 0 ;

	for(it1 = L.begin() ;it1!=L.end() ;++it1){
		in val = *it1 ;
		//cout<<val<<endl;
		if((s1*A)/sum>=B){
			cout<<ans<<endl ;
			return 0 ;
		}
		else {
			ans++ ;
			sum-=val ;
		}
	}
	cout<<r<<endl ;
	return 0 ;
}