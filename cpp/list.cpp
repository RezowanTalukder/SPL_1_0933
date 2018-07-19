#include <bits/stdc++.h>

using namespace std ;

bool near(int a ,int b){
	return abs(a-b)<3 ;
}

int main()
{
	list<int>L ;
	list<int>::iterator it ;

	for(int i=0 ;i<10 ;i++){
		L.push_back(i) ;
	}

	L.remove(5) ;

	for( it=L.begin() ;it!=L.end() ;++it){
		int val = *it ;
		val*=10 ;
		L.push_front(val) ;
	}
	cout<<"First"<<endl;
	for( it=L.begin() ;it!=L.end() ;++it){
		cout<<*it<<endl ;
	}

	L.sort() ;

	cout<<"First"<<endl;
	for( it=L.begin() ;it!=L.end() ;++it){
		cout<<*it<<endl ;
	}
	L.remove(1222) ;

	cout<<"First"<<endl;
	for( it=L.begin() ;it!=L.end() ;++it){
		cout<<*it<<endl ;
	}

	L.unique(near) ;
	cout<<"First"<<endl;
	for( it=L.begin() ;it!=L.end() ;++it){
		cout<<*it<<endl ;
	}
	return 0 ;
}