#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int x1,x2,y1,y2,r ;
    cin>>r>>x1>>y1>>x2>>y2 ;
    double dist = sqrt(abs((x1-x2)*(x1-x2))+abs((y1-y2)*(y1-y2))) ;
    double rad = (dist+(double)r)/2 ;
    cout<<rad<<endl ;
    return 0 ;
}
