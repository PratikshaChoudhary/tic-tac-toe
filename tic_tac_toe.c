
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

char board[3][3];
int Comp_wins, user_wins;

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
      
    printf("\t | %c | %c  | %c | \n", board[0][0], board[0][1], board[0][2]); 
    printf("\t | %c | %c  | %c | \n", board[1][0], board[1][1], board[1][2]); 
    printf("\t | %c | %c  | %c | \n\n", board[2][0], board[2][1], board[2][2]); 
} 

void print_scorecard(){

    printf("\n");
    printf("Scorecard :\n");
    printf("\t\t| Computer | User |\n");
    printf("\t\t|   %d      |  %d   |\n\n",Comp_wins,user_wins);
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
    printf("\nComputer's move :");
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
            goto again;
        }
    return ' ';
}


char *user_turn(int user, int i){
    char str[11];
    int r, c;

    again:
    printf("tictactoe>");
    scanf("%s",str);

    switch(str[0]){
        case 'm':    
            scanf("%d , %d",&r, &c);

            if(board[r][c] == ' '){
                board[r][c] = user;
                if(i>2){
                    if(check(r,c,board[r][c]) == 1){
                        return 'u';                        
                    }
                }
            }
            else  if(r > 2 || c > 2 || r < 0 || c < 0){
                printf("Invalid Move \n");
                goto again;
            }
            else{
                printf("Invalid move, place already taken\n");
                goto again;
            }
            break;
        case 'q':
            return 'c';
        case 's': 
            print_scorecard();
            return 's';
    }
    return ' ';
}


int play(char user, char comp){
  
    char status =' ';

    for(int i = 1; i <= 9; i++){
        repeat:
        if(i%2 != 0){
            if(user == 'X')
                status = user_turn(user, i);
            else
                status = comp_turn(comp, i);
        }else {
            if(user == 'O')
                status = user_turn(user, i);
            else 
                status =  comp_turn(comp, i);
        }
        if(status == 's') {
            goto repeat;
        }
        printf("\n");
        print_board();
        if(status == 'u'){
            user_wins++;
            printf("User wins");
            return 0;
        }
        else if(status == 'c'){
            Comp_wins++;
            printf("Computer Wins");
            return 0;
        }
        else if(status == 'q'){
            return 1;
        }
    }
    printf("The Game is Draw\n");  
    return 0;   
}


int main(){

    char user, comp, c;
    int noOfMatches = 1;
    user_wins = 0;
    Comp_wins = 0;

    srand(time(0));

    while(c != 'e'){
        
        printf("\n\n______________\n\n");
        printf("New Game :\n");
        printf("______________\n\n");

        user = choose_ran();
        comp = (user == 'X' ? 'O' : 'X');

        initilize_board();
        
        if( play(user, comp) == 1){
            printf("\nUser Exit the Game");
            printf("\n\nScorecard After %d  match:\n",noOfMatches);
            print_scorecard();
           break;
        }
        
        printf("\n\nScorecard After %d  match:\n",noOfMatches);
        print_scorecard();
        
        noOfMatches++;
        
        printf("\nPress any kew execpt 'e' to play New Game or 'e' to Exit:");
        scanf("\n");
        scanf("%c",&c);
    }

    return 0;
}
