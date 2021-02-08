
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

char board[3][3];

void print_board(){

    printf("\n\n"); 
      
    printf("\t | %c | %c  | %c | \n", board[0][0],board[0][1], board[0][2]); 
    printf("\t | %c | %c  | %c | \n", board[1][0],board[1][1], board[1][2]); 
    printf("\t | %c | %c  | %c | \n", board[2][0],board[2][1], board[2][2]); 
} 


char choose_ran(){
  return ((rand() % 10) > 5 ?  'X' : 'O');
}

int check(int r, int c, char v){

    if(board[r][0] ==v  && board[r][1] == v &&  board[r][2] == v)
        return 1;
    if(board[0][c] == v && board[1][c] == v &&  board[2][c] == v)
        return 1;
    if((r+c)%2 == 0){
        if( r == 1  && c == 1){
            if(board[0][0] ==v  && board[1][1] == v &&  board[2][2] == v)
                return 1;

            if(board[2][0] ==v  && board[1][1] == v &&  board[0][2] == v)
                return 1;
        }
        else{
            if(r == c){
                if(board[0][0] ==v  && board[1][1] == v &&  board[2][2] == v)
                    return 1;
                else {
                    if(board[2][0] ==v  && board[1][1] == v &&  board[0][2] == v)
                        return 1;
                }

            }
        }

    }
return 0;
}


char *comp_turn(int comp,int i){
    int r, c;
    again:
    r = rand()%3;
    c = rand()%3;
    if(board[r][c] == ' '){
        board[r][c] = comp;
            if(i>2){
                if(check(r,c,board[r][c]) == 1){
                    return 'c';                        
                }
            }
        }
        else{
            printf("Invalid move, place already taken\n");
            goto again;
        }
    return ' ';
}


char *user_turn(int user, int i){
    char str[5];
    int r, c;

    again:
    printf("tictactoe>");
    scanf("%s",str);

    switch(str[0]){
        case 'm':    
            scanf("%d , %d",&r, &c);
            printf("%c   %d   %d",str[0],r,c);

            if(board[r][c] == ' '){
                board[r][c] = user;
                if(i>2){
                    if(check(r,c,board[r][c]) == 1){
                        return 'u';                        
                    }
                }
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


void play(char user, char comp){
  
    char status;

    for(int i = 1; i < 9; i++){
        if(i%2 != 0){
            if(user == 'X')
            status = user_turn(user, i);
            else
                comp_turn(comp, i);
        }else {
            if(user == 'O')
                status = user_turn(user, i);
            else 
                comp_turn(comp, i);
        }
        print_board(i);
        if(status == 'u'){
            printf("User wins");
            return ;
        }
        else if(status == 'c'){
            printf("Computer Wins");
            return ;
        }
    }     
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

    srand(time(0));
    user = choose_ran();
    comp = (user == 'X' ? 'O' : 'X');
    initilize_board();
    printf("%c %c\n",user,comp);
    play(user, comp);

    return 0;
}
