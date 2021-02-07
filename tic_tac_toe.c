#include<stdio.h>
#include <stdlib.h>


char board[3][3];

char choose_ran(){
  return ((rand() % 10) > 5 ?  'X' : 'O');
}


void initilize_board(){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
}


void print_board(){

    printf("\n\n"); 
      
    printf("\t | %c | %c  | %c | \n", board[0][0],board[0][1], board[0][2]); 
    printf("\t | %c | %c  | %c | \n", board[1][0],board[1][1], board[1][2]); 
    printf("\t | %c | %c  | %c | \n", board[2][0],board[2][1], board[2][2]); 
} 


void play(char user, char comp){
  
    char status;
    char str[5];
    int r, c;


    for(int i = 1; i < 9; i++){
     
        again:
        printf("tictactoe>");
        scanf("%s",str);

        switch(str[0]){
            case 'm':    
                scanf("%d , %d",&r, &c);
                printf("%c   %d   %d",str[0],r,c);

                if(board[r][c] == ' '){
                    board[r][c] = user;
                  
                }
                else{
                    printf("Invalid move, place already taken\n");
                    goto again;
                }
                break;
            case 'q':
                return 'c';

        }
        return ' ';
    }     
    
}


int main(){

    char user, comp;

    srand(time(0));
    user = choose_ran();
    comp = (user == 'X' ? 'O' : 'X');

    initilize_board();
    print_board();
    play(user, comp);

    return 0;
}
