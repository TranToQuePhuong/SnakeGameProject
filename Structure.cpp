#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int width=25;
const int height=25;
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
for (i=0;i<=height+1;i++){
    for (j=0;j<=width+1;j++){
         if (i==0||i==height+1||j==0||j==width+1){
            printf("* ");
            }
            else{
				if(i==y && j==x)
            		printf("O ");
            	else if(i==fruitY&&j==fruitX)
              	/*  SetConsoleTextAttribute()*/
                	printf(" F");
            	else{
					 if(i==fruitYdie && j==fruitXdie)
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
            if(dir!=RIGHT){
            	dir = LEFT;
            	moves++;
            }
            break;
        case 'd':
        case 'D':
            if(dir!=LEFT){
            	dir = RIGHT;
            	moves++;
            }
            break;
        case 'w':
        case 'W':
            if(dir!=DOWN){
            	dir = UP;
            	moves++;
            }
            break;
        case 's':
        case 'S':
            if(dir!=UP){
            	dir = DOWN;
            	moves++;
            }
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
    if(y>height){
        y=1;
    }
    if(y<1){
        y=height;
    }
    if(x>width){
        x=1;
    }
    if(x<0){
        x=width;
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
        fruitX = rand()%(width+1);
        fruitY = rand()%(height+1);
        nTail++;
        if (fruitX==0)
            fruitX++;
        if (fruitY==0)
            fruitY++;
        if(score%10==0 && nTail!=0){
            fruitXdie = rand()%(width+1);
            fruitYdie = rand()%(height+1);
            if (fruitXdie==0)
            	fruitXdie++;
            if (fruitYdie==0)
            	fruitYdie++;
    	}
        if(score%20==0 && nTail!=0){
            bigfruitX = rand()%(width+1);
            bigfruitY = rand()%(height+1);
            if (bigfruitX==0)
            bigfruitX++;
            if (bigfruitY==0)
            bigfruitY++;
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

