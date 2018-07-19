#include<graphics.h>
#include<conio.h>


using namespace std ;

int main()
{
    int gd=DETECT ,gm ;
    initgraph(&gd,&gm,"C:\\TC\\BGI") ;

    rectangle(10,10,800,700) ;

    circle(120,109,78) ;

    getch() ;
    closegraph() ;

    return 0;
}
