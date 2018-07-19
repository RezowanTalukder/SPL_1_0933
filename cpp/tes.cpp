#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int i,j=0,k=0,h=0;
	string s;
	cin>>s;
	for(i=0;i<s.length();++i){
		h+=s[i]-48;
		j++;
		if((s[i]-48)%3==0 || h%3==0 || j==3)
		{
			k++;
			h=0;
			j=0;
		}
	}
	cout<<k<<endl;
	return 0;
}
