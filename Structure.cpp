#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int width=50;
const int height=20;
int i,j,x,y,fruitX,fruitY,score;
bool gameover;
enum eDirec{STOP =0,LEFT,RIGHT,UP,DOWN};
enum eDirec dir;
void Setup(){
	gameover = false;
    x = width/2;
    y=height/2;
    fruitX=rand()/width;
    fruitY=rand()/height;
    score=0;
}

void Draw(){
    system("cls"); //system clear
for (i=0;i<=height;i++){
    for (j=0;j<=width;j++){
        if (i==0||i==height){
            printf("+ ");}
        else{
            if(j==0||j==width)
            printf("+ ");
            else
                printf("  ");}}

    printf("\n");
}
            printf("GAME START! \t\t\t Score:");
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
}

int main(){
    Setup();
    while(!gameover){
        Sleep(100);
        Draw();
        Input();
        Logic();
    }
    return 0;
}

