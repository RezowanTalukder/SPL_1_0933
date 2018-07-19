#include <stdlib.h>
#include<stdio.h>


int someone_wins(char **board, char letter) ;
void init_board(char **board) ;
void update_board(char **board, int hor, int vert, int player) ;
void print_board(char **board) ;
int max(int a, int b) ;
int min(int a, int b) ;
char **copy_board(char **board1) ;
int someone_wins(char **board, char letter) ;

typedef struct legal_move *move;


struct legal_move {
  int hor;
  int vert;
};



void init_board(char **board)
{
  int i, j;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      board[i][j] = '@';
    }
  }

  return;
}


void update_board(char **board, int hor, int vert, int player)
{
      if (player) {
            board[hor][vert] = 'X' ;
      }
      else {
            board[hor][vert] = 'O' ;
      }

      return;
}


void print_board(char **board)
{
      int i, j;

      for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
          putchar(board[i][j]);
          if (j == 2) {
        putchar('\n');
          }
        }
      }
      putchar ('\n');

      return;
}




int max(int a, int b)
{
      if (a >= b) {
            return a;
      }
      else {
            return b;
      }
}

int min(int a, int b)
{
      if (a >= b) {
            return b;
      }
      else {
            return a;
      }
}

move *find_moves(char **board, int *num_moves)
{
      int i, j;
      int count_moves = 0;


      move *move_array = (move *) malloc(sizeof(move) * 9);

      for (i=0; i<9; i++) {
            move_array[i] = (move) malloc (sizeof(struct legal_move));
      }

      for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
          if (board[i][j] == '@') {
            move_array[count_moves] -> hor = i;
            move_array[count_moves] -> vert = j;
            count_moves++;
          }
        }
      }

      *num_moves = count_moves;

      return move_array;
}


char **copy_board(char **board1)
{
      int i, j;

      char **board2 = (char **) malloc (sizeof(char *) * 3);

      for (i=0; i<3; i++) {
            board2[i] = (char *) malloc (sizeof(char) * 3);
      }

      for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            board2[i][j] = board1[i][j];
        }
      }

      return board2;
}


int minimax_recurse(char **board, int player, int depth, move best_move)
{
      int i, j, hor, vert, alpha, subalpha;

      if (someone_wins(board, 'X')) {
            return 1;
      }

      else if (someone_wins(board, 'O')) {
            return -1;
      }

      else if (game_over(board)) {
            return 0;
      }

      if (player) {
            alpha = -1;
      }
      else {
            alpha = 1;
      }

      int num_moves;

      move *moves = find_moves(board, &num_moves);

      for (i=0; i<num_moves; i++) {

        char **dummy_board = copy_board(board);

        hor = moves[i] -> hor;
        vert = moves[i] -> vert;

        update_board(dummy_board, hor, vert, player);


        subalpha = minimax_recurse(dummy_board, !player, (depth + 1), best_move);

        if (player) {
           if (!depth && (alpha <= subalpha)) {
                best_move -> hor = moves[i] -> hor;
                best_move -> vert = moves[i] -> vert;
           }

          alpha = max(alpha, subalpha);
        }

        else alpha = min(alpha, subalpha);

        for (j=0; j<3; j++) {
            free(dummy_board[j]);
        }
        free(dummy_board);
    }

    return alpha;
}


int minimax(char **board, int curplayer, move best_move)
{
    return minimax_recurse(board, curplayer, 0, best_move);
}


int game_over(char **board)
{
  int i, j;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      if (board[i][j] == '@') {
            return 0;
      }
    }
  }

  return 1;
}


int same_letter(char *line, char letter)
{
  int i;

  for (i=0; i<3; i++) {
    if (line[i] != letter) {
      return 0;
    }
  }

  return 1;
}


int someone_wins(char **board, char letter)
{

  if ((same_letter(board[0], letter)) || (same_letter(board[1], letter)) || (same_letter(board[2], letter))) {
        return 1;
  }


  int i;
  int j = -1;
  char column[3];

  while (j++ < 3) {
    for (i=0; i<3; i++) {
      column[i] = board[i][j];
    }
    if (same_letter(column, letter)) {
      return 1;
    }
  }


  if (((board[0][0] == letter) && (board[1][1] == letter) && (board[2][2] == letter)) ||
      ((board [0][2] == letter) && (board[1][1] == letter) && (board[2][0] == letter)))
      {
            return 1;
      }

  return 0;
}


void print_usage()
{
  printf("You are 0 \n please insert the row and column: \n");
  return;

}


void draw()
{
      printf("Draw\n");
      exit(1);
}


void ai_wins()
{
      printf("You Lost\n");
      exit(1);
}

int main()
{

      int i ;
      char **board = (char **) malloc (sizeof(char *) * 3);

      for (i=0; i<3; i++) {
            board[i] = (char *) malloc (sizeof(char) * 3);
      }

      print_usage();
      init_board(board);


      int hor, vert, alpha ;
      move best_move = (move) malloc (sizeof(struct legal_move));

      print_board(board);

      while (!game_over(board) && (!someone_wins(board, 'X'))) {
        scanf("%d %d", &hor, &vert);
        hor -= 1;
        vert -= 1;

        if ((hor > 2) || (vert > 2) || (hor < 0) || (vert < 0)) {
             printf("Out of Bound\n");
        }
        else if (board[hor][vert] != '@') {
              printf("Already Booked\n");
        }

        else {
              update_board(board, hor, vert, 0);

              printf("The position after your last move:\n");

              print_board(board);

              alpha = minimax(board, 1, best_move);

              update_board(board, best_move -> hor, best_move -> vert, 1);

              printf("The position after the computer's last move:\n

              print_board(board);

          }
      }

      if (someone_wins(board, 'X')) {
            ai_wins();
      }
      else {
            draw();
      }

      return 0;
}
