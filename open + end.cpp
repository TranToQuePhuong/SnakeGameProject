void load(){
    int r,c,q;
	printf("\t\t\t\tWelcome to snake game.\n");
    printf("\t\t\t\t      Loading...\n\t\t\t\t");
    for(r=1;r<=21;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void gameover(){
	system("cls");
	printf("\t\t\t\tGame over!\n (Press any key to exit the game)");
	getch();}
