#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void print_board(Board b)
{
    setcolor(WHITE);
    int cx,cy;
    for(int i=0; i<5; i++)
    {
        line(500+i,100,500+i,700);
        line(700+i,100,700+i,700);
        line(300,300+i,900,300+i);
        line(300,500+i,900,500+i);
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(b.board[i][j]==1)
            {
                cx=400+(j*200);
                cy=200+(i*200);
                print_cross(cx,cy,70);

            }
            else if(b.board[i][j]==2)
            {
                cx=400+(j*200);
                cy=200+(i*200);
                print_circle(cx,cy,50);
            }
        }
    }
}

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN) ;
    DWORD screenHeight = GetSystemMetrics(SM_CXSCREEN) ;

    initwindow(screenWidth,screenHeight,"Tick Tack Toe") ;

    POINT cursorPosition ;
    int mX,mY ;

    settextstyle(1,0,2);
    outtextxy(950,100,"CLICK ON THE CELL ");
    outtextxy(950,150," TO MAKE MOVE");
    Board tic_toc_toe_board ;
    tic_toc_toe_board.clear_cells() ;

    print_board(tic_toc_toe_board);


    getch();
    closegraph();
    return 0;
}
