#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int width=50;
const int height=20;
int i,j,x,y,fruitX,fruitY,score,gameover=0;

void Setup(){
	gameover = 0;
    x = width/2;
    y=height/2;
    fruitX=rand()/width;
    fruitY=rand()/height;
    score=0;
}

void Draw(){
    system("cls"); //system clear
    int i,j,height,width;
printf("Enter the size of block <height,width>:");
scanf("%d""%d",&height,&width);
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

}

void Logic(){
}

void main(){
    Setup();
    while(gameover==0){
        Sleep(100);
        Draw();
        Input();
        Logic();
    }
}

