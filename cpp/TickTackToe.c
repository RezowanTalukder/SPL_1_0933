#include<stdio.h>
#include<string.h>

char board[9] = "555555555" ;ok
int human = 0 , ai = 1 ;
bool free[9] ;
int available[9] ;

void winning(char *board , int player) ;
void emptyGhor(char *board) ;
void minimax(char *board,int ai) ;

void emptyGhor(char *board)
{
    int i  ;
    for(i=0 ;i<9 ;i++){
        if(atoi(board[i])!=5)free[i] = false ;
    }
}


void winning(char *board , int player)
{
    if(
        (atoi(board[0])==player && atoi(board[1])==player &&atoi(board[2])==player )||
        (atoi(board[3])==player && atoi(board[4])==player &&atoi(board[5])==player )||
        (atoi(board[6])==player && atoi(board[7])==player &&atoi(board[8])==player )||
        (atoi(board[0])==player && atoi(board[3])==player &&atoi(board[6])==player )||
        (atoi(board[1])==player && atoi(board[4])==player &&atoi(board[7])==player )||
        (atoi(board[2])==player && atoi(board[5])==player &&atoi(board[8])==player )||
        (atoi(board[0])==player && atoi(board[4])==player &&atoi(board[8])==player )||
        (atoi(board[2])==player && atoi(board[4])==player &&atoi(board[6])==player )
    ){
        return true ;
    }
    else return false ;
}

int availableSpot(*board)
{
    int i=0 ,cn = 0 ;
    for(i=0 ;i<9 ;i++){
        if(free==true)cn++ ;
    }
    return cn ;
}

int minimax(char *board,int ai)
{
    emptyGhor(board) ;

    int a = availableSpot(board) ;

    if(winning(board,human)){
        return -10 ;
    }
    else if(winning(board,ai)){
        return 10 ;
    }
    else if(a==0){
        return 0 ;
    }



    for(int i=0 ;i<a ;i++){

    }

}

void PrintBoard()
{
    printf("Tick tack toe\n\n\n") ;
    printf("\t %c\t%c\t%c\n",board[0],board[1],board[2]) ;
    printf("\t %c\t%c\t%c\n",board[3],board[4],board[5]) ;
    printf("\t %c\t%c\t%c\n",board[6],board[7],board[8]) ;
}

int main()
{
    int i ;

    for( i=0 ;i<9 ;i++)free[i] = true ;

    printBoard() ;

    int bestPoint = minimax(board,ai) ;

    board[bestPoint] = '1' ;
    free[bestPoint] = false ;


    return 0 ;
}
