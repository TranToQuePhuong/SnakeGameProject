#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int width=50;
const int height=20;
int i,j,x,y,fruitX,fruitY,fruitXdie,fruitYdie,score;
bool gameover;
enum eDirec{STOP =0,LEFT,RIGHT,UP,DOWN};
enum eDirec dir;

void Setup(){
    srand(time(NULL));
	gameover = false;
	dir = STOP;
    x = width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void Draw(){
    clearScreen(); //system clear
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
        case 'A':
            if(dir!=RIGHT)
            dir = LEFT;
            break;
        case 'd':
        case 'D':
            if(dir!=LEFT)
            dir = RIGHT;
            break;
        case 'w':
        case 'W':
            if(dir!=DOWN)
            dir = UP;
            break;
        case 's':
        case 'S':
            if(dir!=UP)
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
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
    if(y<1){
        y=height-1;
    }
    if(x>=width){
        x=0;
    }
    if(x<0){
        x=width-1;
    }
     if(fruitXdie==x && fruitYdie==y){
        gameover=true;
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
    ShowConsoleCursor(false);
    Setup();
    while(!gameover){
        Sleep(10);
        Draw();
        Input();
        Logic();
    }
return 0;
}
