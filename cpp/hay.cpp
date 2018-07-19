#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int t1 = 0, t2 = 1, nextTerm = 0, n ;
    char fib[10001] ;

    nextTerm = t1 + t2;
    cin>>n;
    for(int i=0 ;i<n ;i++)fib[i] = 'o' ;
    fib[0] = 'O' ;
    fib[1] = 'O' ;

    while(nextTerm<= n)
    {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
        fib[nextTerm-1] = 'O' ;
    }
    for(int i=0 ;i<n ;i++)cout<<fib[i] ;

    return 0 ;
}
