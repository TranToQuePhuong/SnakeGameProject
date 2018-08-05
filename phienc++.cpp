#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int width=50;
const int height=20;
int i,j,x,y,fruitX,fruitY,fruitXdie,fruitYdie,score,gameover=0;
enum eDirec{STOP =0,LEFT,RIGHT,UP,DOWN};
enum eDirec dir;

void Setup(){
    srand(time(NULL));
	gameover = 0;
	dir = STOP;
    x = width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void Draw(){
    system("cls"); //system clear
    int i,j;
for (i=0;i<=height;i++){
    for (j=0;j<=width;j++){
        if (i==0||i==height){
            printf("+ ");}
        else{
            if(j==0||j==width)
            printf("+ ");
            if(j==0||j==width)
                printf("+ ");
            if(y>=height){
                y=1;
            }
            if(y<1) {
                y=height-1;
            }
            if(x>=width){
                x=0;
            }
            if(x<0) {
                x=width-1;
            }
            if(i==y && j==x)
            printf("O ");
            else if(i==fruitY&&j==fruitX)
              /*  SetConsoleTextAttribute()*/
                printf(" F");
            else if(i==fruitYdie && j==fruitXdie)
                    printf(" D");
            else
                printf("  ");}}

    printf("\n");
}
            printf("GAME START! \t\t\t Score: %d",score);
}

void Input(){
 if(kbhit()){
        char strInput = getch();
        switch(strInput){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void Logic(){
     switch(dir){
    case LEFT:
        x--;

        break;
    case RIGHT:
        x++;

        break;
    case UP:
        y--;

        break;
    case DOWN:
        y++;

        break;
    default:
        break;
    }
     if(fruitXdie==x && fruitYdie==y){
        gameover=1;
    }
    else if(fruitX==x&&fruitY==y){
        fruitXdie = 100;
        fruitYdie = 100;
        score++;
        fruitX = rand()%width;
        fruitY = rand()%height;
        if(score%10==0 && score!=0){
            fruitXdie = rand()%width;
            fruitYdie = rand()%height;
        if (fruitX==0)
            fruitX++;
        if (fruitX==width)
            fruitX--;
        if (fruitY==0)
            fruitY++;
        if (fruitY==height)
            fruitY--;
        }
    }
}
int main(){
    Setup();
    while(gameover==0){
        Sleep(10);
        Draw();
        Input();
        Logic();
    }
return 0;
}
