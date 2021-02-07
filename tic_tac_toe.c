#include<stdio.h>
#include <stdlib.h>


char board[3][3];

void print_board(){

    printf("\n\n"); 
      
    printf("\t | %c | %c  | %c | \n", board[0][0],board[0][1], board[0][2]); 
    printf("\t | %c | %c  | %c | \n", board[1][0],board[1][1], board[1][2]); 
    printf("\t | %c | %c  | %c | \n", board[2][0],board[2][1], board[2][2]); 
} 


void initilize_board(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
}


int main(){

    char user, comp;

    initilize_board();
    print_board();

    return 0;
}
