#include<stdio.h>

#include<stdlib.h>
#include<ncurses.h>

struct myDataType{
    int i;
    char ch;
}inputValue();

void run();
int check(char sym[9],char ch,int count);
struct myDataType inputValue(char sym[9],int count);
void Display(char sym[9]);

void main(){
initscr();
    char reStart;
    again:
	run();
	mvaddstr(1, 33, "\nIf You Want To Play Again Press 1: \nElse Any:");
	scanf("%s",&reStart);
	if(reStart == '1')
        {
            system("cls");
            goto again;
        }
    else
        exit(0);
}

void run(){
    int count = 0;
    struct myDataType info;
    char symbol[9] = {'1','2','3','4','5','6','7','8','9'};
    Display(symbol);
    again:
    info = inputValue(symbol,count);
    symbol[info.i] = info.ch;
    system("cls");
    Display(symbol);
    if(check(symbol,info.ch,count)==1);
    else{
        count++;
        goto again;
    }
}
int check(char sym[9],char ch,int count){
    int i;
    for(i = 0;i<=6; i+=3)//it's for row
        if(sym[i] == ch && sym[i+1]==ch&&sym[i+2]==ch){
            mvaddstr(3, 33, "the Winner is : %c",ch);return 1;
        }
    for(i = 0;i<3; i++)//it's for column
        if(sym[i]==ch && sym[i+3]==ch&&sym[i+6]==ch){
            mvaddstr(3, 33, "the Winner is : %c",ch);return 1;
        }
    if(sym[0]==ch && sym[4]==ch&&sym[8]==ch){
            mvaddstr(4, 33, "the Winner is : %c",ch);return 1;
        }
    else if(sym[2]==ch && sym[4]==ch && sym[6]==ch){
            mvaddstr(5, 33, "the Winner is : %c",ch);return 1;
        }
    else if(count==8){
        mvaddstr(6, 33, "the Game is DRAW");
        return 1;
    }else return 0;
}
struct myDataType inputValue(char sym[9],int count){
    char value;
    int i;
    struct myDataType info;
    inputAgain:
    if(count%2 == 0){
        mvaddstr(7, 33, "\nEnter Your Choice X:");
    }else{
        mvaddstr(8, 33, "\nEnter Your Choice O:");
    }
    scanf("%s",&value);
    for(i=0;i<9;i++){

        if(value == sym[i]){
            info.i = i;
            if(count%2 == 0)
                info.ch = 'X';
            else
                info.ch = 'O';
            break;
        }else{
            info.i = -1;
            info.ch = ' ';
        }
    }
    if(info.i == -1){
        mvaddstr(9, 33, "\nInput is not Valid");
        goto inputAgain;
    }
    return info;
}

void Display(char sym[9]){
	mvaddstr(10, 33, "\t\t\t\tT i c	t a c	t o e");
	mvaddstr(11, 33, "\nPlayers 1 Symbol: X");
	mvaddstr(12, 33, "\nPlayers 2 Symbol: O");
	mvaddstr(13, 33, "\n\t\t\t       |       |       ");
	mvaddstr(14, 33, "\n\t\t\t   %c   |   %c   |   %c   ",sym[0],sym[1],sym[2]);
	mvaddstr(15, 33, "\n\t\t\t-------|-------|-------");
	mvaddstr(16, 33, "\n\t\t\t   %c   |   %c   |   %c   ",sym[3],sym[4],sym[5]);
	mvaddstr(17, 33, "\n\t\t\t-------|-------|-------");
	mvaddstr(18, 33, "\n\t\t\t   %c   |   %c   |   %c   ",sym[6],sym[7],sym[8]);
	mvaddstr(19, 33, "\n\t\t\t       |       |       ");
}
