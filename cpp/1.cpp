#include <bits/stdc++.h>
#include <map>
using namespace std ;
int main ()
{
   unordered_map<char,int> mymap;
   unordered_map<char,int>::iterator it;


  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    cout<<"............."<<endl ;


    cout<<mymap.size()<<endl ;

    mymap.erase(mymap.size()-1) ;

    cout<<mymap.size()<<endl ;


  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
