
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

char board[3][3];
int userVSuser[2], userVScomp[2];

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

void print_scorecard1(){

    printf("\n");
    printf("Scorecard :\n");
    printf("\t\t| Computer | User |\n");
    printf("\t\t|   %d      |  %d   |\n\n",userVScomp[0],userVScomp[1]);
}

void print_scorecard2(){

    printf("\n");
    printf("Scorecard :\n");
    printf("\t\t| User1 | User2 |\n");
    printf("\t\t|   %d      |  %d   |\n\n",userVSuser[0],userVSuser[1]);
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


char *user_turn(int user, int i, int choice){
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
            if(choice == 1)
                return 'c';
            else
                return 'q';
        break;
        case 's': 
            if(choice == 1)
                print_scorecard1();
            else
                print_scorecard2();
            return 's';
        break;
    }
    return ' ';
}


int playWithComp(char user, char comp){
  
    char status =' ';

    for(int i = 1; i <= 9; i++){
        repeat:
        if(i%2 != 0){
            if(user == 'X')
                status = user_turn(user, i, 1);
            else
                status = comp_turn(comp, i);
        }else {
            if(user == 'O')
                status = user_turn(user, i, 1);
            else 
                status =  comp_turn(comp, i);
        }
        if(status == 's') {
            goto repeat;
        }
        printf("\n");
        print_board();
        if(status == 'u'){
            userVScomp[1]++;
            printf("User wins");
            return 0;
        }
        else if(status == 'c'){
            userVScomp[0]++;
            printf("Computer Wins");
            return 0;
        }
    }
    printf("The Game is Draw\n");  
    return 0;   
}

int playWithUser(char user1, char user2){
  
    char status =' ';
    int user = 0;

    for(int i = 1; i <= 9; i++){
        repeat:
        if(i%2 != 0){
            if(user1 == 'X'){
                printf("User 1  Turn :\n");
                user = 1;
                status = user_turn(user1, i, 2);
            }            
            else{
                printf("User 2  Turn :\n");
                user = 2;
                status = user_turn(user2, i, 2);
            }
        }else {
            if(user1 == 'O'){
                printf("User 1  Turn :\n");
                user = 1;
                status = user_turn(user1, i, 2);                
            }
            else{
                printf("User 2  Turn :\n");
                user = 2;
                status =  user_turn(user2, i, 2);
            }
        }

        if(status == 's') {
            goto repeat;
        }
        printf("\n");
        print_board();
        if(status == 'u'){
            if(user == 1){
                userVSuser[0]++;
                printf("User1 wins");
            }
            else{
                userVSuser[1]++;
                printf("User2 wins");                
            }
            return 0;
        }
        else if(status == 'c'){
            if(user == 2){
                userVSuser[1]++;
                printf("User2 wins");                
            }
            else{
                userVSuser[0]++;
                printf("User1 wins");                

            }
            return 0;
        }
        else if(status == 'q'){
            if(user == 1){
                userVSuser[1]++;
                printf("User2 wins");
            }
            else{
                userVSuser[0]++;
                printf("User1 wins");                
            }
            return 0;
        }
    }
    printf("The Game is Draw\n");  
    return 0;   
}

int main(){

    char user1, user2, c;
    int choice;
    int noOfMatches1 = 1, noOfMatches2 = 1;

    userVScomp[0] = userVScomp[1] = 0;
    userVSuser[0] = userVSuser[1] = 0;

    srand(time(0));

    while(c != 'e'){
        
        printf("\n\n______________\n\n");
        printf("New Game :\n");
        printf("______________\n\n");

        printf(" press 1 to play With Computer\n press 2 to Play With human\n Enter Your choice: ");
        scanf("%d",&choice);
        
        user1 = choose_ran();
        user2 = (user1 == 'X' ? 'O' : 'X');

        initilize_board();
        
        if(choice == 1){
            printf("\t\t\tGame b/w Human and Computer\n\n");
            if( playWithComp(user1, user2) == 1){
                printf("\nUser Exit the Game");
                printf("\n\nScorecard After %d  match:\n",noOfMatches1);
                print_scorecard1();
               break;
            }

            printf("\n\nScorecard After %d  match:\n",noOfMatches1);
            print_scorecard1();
            noOfMatches1++;
        }
        else{
            printf("\t\t\tGame b/w Human and Human\n\n");
            if( playWithUser(user1, user2) == 1){
                printf("\nUser Exit the Game");
                printf("\n\nScorecard After %d  match:\n",noOfMatches2);
                print_scorecard2();
               break;
            }

            printf("\n\nScorecard After %d  match:\n",noOfMatches2);
            print_scorecard2();
            noOfMatches2++;
        }
                       
        printf("\nPress any kew execpt 'e' to play New Game or 'e' to Exit:");
        scanf("\n");
        scanf("%c",&c);
    }

    return 0;
}