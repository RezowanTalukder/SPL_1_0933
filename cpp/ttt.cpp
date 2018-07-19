#include<graphics.h>
#include<bits/stdc++.h>

#define DRAW 5

using namespace std;

void print_cross(int x,int y,int l);
void print_circle(int x,int y, int r);
int get_cell_no(int x,int y,int &cx,int &cy);

int maximum(int a[],int n);
int minimum(int a[],int n);
int end_options();

class Board
{
public:
    int board[3][3];
    Board()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                board[i][j]=0;
            }
        }
    }
    void show()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<board[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    void clear_cells()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                board[i][j]=0;
            }
        }
    }
    void make_move(int n,int player)
    {
        int i=n/3;
        int j=n%3;
        if(player == 1)
        {
            board[i][j]=1;
        }
        else if(player == 2)
        {
            board[i][j]=2;
        }

    }
    int is_cell_empty(int n)
    {
        int i=n/3;
        int j=n%3;
        if((board[i][j]!=1)&&(board[i][j]!=2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void clone(Board b)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                this->board[i][j] =b.board[i][j] ;
            }
        }
    }
    int result()
    {
        int checker=0;
        int a,i,j;
        for(i=0; i<3; i++)
        {
            a=board[i][0];
            for(j=0; j<3; j++)
            {
                if(board[i][j]!=a)
                {
                    checker=1;
                    break;
                }
            }
            if(checker==0)
            {
                if(a==1)
                {
                    return -1;
                }
                else if(a==2)
                {
                    return 1;
                }
            }
            checker=0;
        }
        for(i=0; i<3; i++)
        {
            a=board[0][i];
            for(j=0; j<3; j++)
            {
                if(board[j][i]!=a)
                {
                    checker=1;
                    break;
                }
            }
            if(checker==0)
            {
                if(a==1)
                {
                    return -1;
                }
                else if(a==2)
                {
                    return 1;
                }
            }
            checker=0;
        }
        a = board[0][0];
        checker=0;
        for(i=0,j=0; i<3; i++,j++)
        {
            if(board[i][j]!=a)
            {
                checker=1;
                break;
            }
        }
        if(checker==0)
        {
            if(a==1)
            {
                return -1;
            }
            else if(a==2)
            {
                return 1;
            }
        }
        a = board[0][2];
        checker=0;
        for(i=0,j=2; i<3; i++,j--)
        {
            if(board[i][j]!=a)
            {
                checker=1;
                break;
            }
        }
        if(checker==0)
        {
            if(a==1)
            {
                return -1;
            }
            else if(a==2)
            {
                return 1;
            }
        }
        for(i=0; i<9; i++)
        {
            if(is_cell_empty(i)==1)
            {
                return 0;
            }
        }
        return DRAW;
    }

};

class Move
{
public:
    Move *parent_address;
    int game_result;
    Board b;
    Move *child[9];
};
Move *game_tree( Move *parent, int step, Board tic_toc_toe_board);

void print_board(Board b);
int main()
{
    int x,y;
    DWORD screen_width=GetSystemMetrics(SM_CXSCREEN);
    DWORD screen_height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(screen_width,screen_height,"TIC TAC TOE");
    settextstyle(1,0,2);
    Board tic_toc_toe_board;
    tic_toc_toe_board.clear_cells();

    print_board(tic_toc_toe_board);
    int move_left=9;
    while(1)
    {

        while(1)
        {
            while(1)
            {
                int mx,my;
                getmouseclick(WM_LBUTTONDOWN, mx, my);
                if((mx>100)&&(mx<900)&&(my>100)&&(my<700))
                {
                    int cell_no=get_cell_no(mx,my,x,y);
                    if((tic_toc_toe_board.is_cell_empty(cell_no))==1)
                    {
                        tic_toc_toe_board.make_move(cell_no,1);
                        print_board(tic_toc_toe_board);
                        move_left--;
                        break;
                    }

                }
                delay(100);
            }
            Move *ptr;
            ptr = game_tree(NULL,move_left,tic_toc_toe_board);
            int result=ptr->game_result;
            for(int i=0; i<move_left; i++)
            {
                if((ptr->child[i]->game_result)==result)
                {
                    tic_toc_toe_board.clone(ptr->child[i]->b);
                    print_board(tic_toc_toe_board);
                    move_left--;
                    break;
                }
            }
            int check_result;
            check_result=tic_toc_toe_board.result();
            if(check_result!=0)
            {
                setcolor(WHITE);
                settextstyle(1,0,7);
                if(check_result==1)
                {
                    outtextxy(200,20,"YOU LOSE");
                }
                else if(check_result==-1)
                {
                    outtextxy(200,20,"YOU WIN");
                }
                else if(check_result==DRAW)
                {
                    outtextxy(200,20,"DRAW");
                }
                break;
            }
        }
        end_options();
        int option=0;
        while(1)
        {
            int mx,my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if((mx>950)&&(mx<1350)&&(my>500)&&(my<550))
            {
                option=1;
                break;
            }
            else if((mx>950)&&(mx<1350)&&(my>650)&&(my<700))
            {
                option=2;
                break;
            }
        }
        if(option==2)
        {
            break;
        }
        else if(option == 1)
        {
            cleardevice();
            setcolor(WHITE);
            settextstyle(1,0,2);
            tic_toc_toe_board.clear_cells();
            print_board(tic_toc_toe_board);
            move_left=9;
        }
    }


    getch();
    closegraph();
    return 0;
}

Move *game_tree( Move *parent, int step, Board tic_toc_toe_board)
{
    int player_no;
    if((step%2)==0)
    {
        player_no=2;
    }
    else if((step%2)!=0)
    {
        player_no=1;
    }
    Move *p = new Move();
    p->parent_address = parent;
    p->b.clone(tic_toc_toe_board);
    int result=p->b.result();
    if((result==1)||(result==-1)||(result==DRAW))
    {
        if(result==1)
        {
            p->game_result=1;

        }
        else if(result==-1)
        {
            p->game_result=-1;
        }
        else if(result==DRAW)
        {
            p->game_result=0;
        }
        for(int i=0; i<9; i++)
        {
            p->child[i]=NULL;
        }
        return p;
    }
    if(step==0)
    {
        for(int i=0; i<9; i++)
        {
            p->child[i] = NULL;
        }
    }
    else if(step!=0)
    {
        int i,j;
        for(i=0,j=0; i<step; j++)
        {
            if((p->b.is_cell_empty(j))==1)
            {
                Board temp;
                temp.clone(p->b);
                temp.make_move(j,player_no);
                p->child[i] = game_tree(p,step-1,temp);
                i++;
            }
        }
        for(; i<9; i++)
        {
            p->child[i] = NULL;
        }
        int probable_results[step];
        for(i=0; i<step; i++)
        {
            probable_results[i]=p->child[i]->game_result;
        }
        int a;
        if((step%2)==0)
        {
            a=maximum(probable_results,step);
        }
        else if((step%2)!=0)
        {
            a=minimum(probable_results,step);
        }
        p->game_result=a;
    }
    return p;
}
int maximum(int a[],int n)
{
    int m=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]>m)
        {
            m=a[i];
        }
    }
    return m;
}
int minimum(int a[],int n)
{
    int m=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}

void print_cross(int x,int y,int l)
{
    setcolor(YELLOW);
    int a=x+(l/2);
    int b=x-(l/2);
    int c=y+(l/2);
    int d=y-(l/2);
    for(int i=0; i<5; i++)
    {
        line(b+i,d,a+i,c);
    }
    for(int i=0; i<5; i++)
    {
        line(a+i,d,b+i,c);
    }
}
void print_circle(int x,int y, int r)
{
    setcolor(GREEN);
    for(int i=0; i<5; i++)
    {
        circle(x,y,r+i);
    }

}
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
int get_cell_no(int x,int y,int &cx,int &cy)
{
    int n;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((x>(300+(j*200)))&&(x<(500+(j*200)))&&(y>(100+(i*200)))&&(y<(300+(i*200))))
            {
                cx=400+(j*200);
                cy=200+(i*200);
                n=(3*i)+j;
                return n;
            }
        }
    }
}
int end_options()
{
    setcolor(WHITE);
    settextstyle(1,0,4);
    outtextxy(980,510,"GOOD GAME");
    outtextxy(980,660,"EXIT");
}
