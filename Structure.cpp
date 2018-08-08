#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int width=50;
const int height=20;
int i,j,k,x,y,fruitX,fruitY,bigfruitX,bigfruitY,fruitXdie,fruitYdie,score,moves=0;
int nTail=0;
bool gameover;
int tailX[100],tailY[100];
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
                else if(i==bigfruitY && j==bigfruitX)
                    printf(" E");
            	else{
            		bool print=false;
            		for(k=0;k<nTail;k++){
            			if (tailX[k]==j && tailY[k]==i){
            				printf("o ");
            				print=true;
						}
					}
					if (!print){
						printf("  ");
					}

			 	}
		}
	}
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
            moves++;
            break;
        case 'd':
        case 'D':
            if(dir!=LEFT)
            dir = RIGHT;
            moves++;
            break;
        case 'w':
        case 'W':
            if(dir!=DOWN)
            dir = UP;
            moves++;
            break;
        case 's':
        case 'S':
            if(dir!=UP)
            dir = DOWN;
            moves++;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void Logic(){
	int prevX=tailX[0];
	int prevY=tailY[0];
	int tmpX,tmpY;
	tailX[0]=x;
	tailY[0]=y;
	for (i=1;i<nTail;i++){
		tmpX=tailX[i];
		tmpY=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=tmpX;
		prevY=tmpY;
	}
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
    if(moves>4){
        bigfruitX=100;
        bigfruitY=100;
    }
     if(fruitXdie==x && fruitYdie==y){
        gameover=true;
    }
    else if(fruitX==x&&fruitY==y){
    	bigfruitX = 100;
        bigfruitY = 100;
        fruitXdie = 100;
        fruitYdie = 100;
        score++;
        moves=0;
        fruitX = rand()%width;
        fruitY = rand()%height;
        nTail++;
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
        if(score%10==0 && score!=0){
            fruitXdie = rand()%width;
            fruitYdie = rand()%height;
            if (fruitXdie==0)
            fruitXdie++;
            if (fruitXdie==width)
            fruitXdie--;
            if (fruitYdie==0)
            fruitYdie++;
            if (fruitYdie==height)
            fruitYdie--;
    	}
        if(score%20==0 && score!=0){
            bigfruitX = rand()%width;
            bigfruitY = rand()%height;
            if (bigfruitX==0)
            bigfruitX++;
            if (bigfruitX==width)
            bigfruitX--;
            if (bigfruitY==0)
            bigfruitY++;
            if (bigfruitY==height)
            bigfruitY--;
            if(bigfruitX==fruitXdie && bigfruitY==fruitYdie){
                    bigfruitX++;
                    bigfruitY++;
    		}
    		 else if(x==bigfruitX && y==bigfruitY){
        		score+=5;
        		bigfruitX = 100;
      		 	bigfruitY = 100;
        		fruitXdie = 100;
        		fruitYdie = 100;
    		}
    	}
	}
}
int main(){
	ShowConsoleCursor(false);
    Setup();
    while(!gameover){
        Sleep(50);
        Draw();
        Input();
        Logic();
    }
    return 0;
}

