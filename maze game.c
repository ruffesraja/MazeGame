#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define TL 218
#define TR 191
#define TC 194
#define CL 195
#define CC 197
#define CR 180
#define BL 192
#define BC 193
#define BR 217
#define HL 196
#define VL 179
#define Xval 37
#define Yval 5
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
int main(){
	int maze[9][9] = {
	{1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,1},
	{1,1,0,1,1,1,1,1,0},
	{0,0,1,0,0,0,1,0,0},
	{1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,0,1,1},
	{0,0,1,0,0,0,1,0,0},
	{1,1,1,1,1,1,1,1,1}
	};
	display_game_name();
	create_table();
	display_stones(maze);
	display_start_end();
	start_game(maze);
	gotoxy(0,25);
	return EXIT_SUCCESS;
}
int isSafe(int maze[9][9],int row,int col){
	if((row<9 && col<9 && row>=0 && col>=0) && maze[row][col]==1){
		return 1;
	}
	return 0;
}
void display_game_name(){
	gotoxy(Xval+18,Yval-1);
	printf("MAZE GAME");
}
void create_table(){
	gotoxy(Xval,Yval+1);
	create_row1();
	printf("\n");
	for(int row=2;row<=18;row++){
		gotoxy(Xval,Yval+row);
		if(row%2==0){
			create_even_row();
		}
		else{
			create_odd_row();
		}
		printf("\n");
	}
	gotoxy(Xval,Yval+19);
	create_row15();
}
void create_row1(){        
	printf("%c",TL);
	for(int itr=1;itr<45;itr++){
		if(itr%5==0){
			printf("%c",TC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",TR);
}
void create_even_row(){
	for(int itr=0;itr<46;itr++){
		if(itr%5==0){
			printf("%c",VL);
		}
		else{
			printf("%c",' ');
		}
	}
}
void create_odd_row(){
	printf("%c",CL);
	for(int itr=1;itr<45;itr++){
		if(itr%5==0){
			printf("%c",CC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",CR);
}
void create_row15(){
	printf("%c",BL);
	for(int itr=1;itr<45;itr++){
		if(itr%5==0){
			printf("%c",BC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",BR);
}

void display_stones(int maze[9][9]){
	gotoxy(39,7);
	int x = Xval+1;
	int y = Yval+2;
	gotoxy(x,y);
	for(int row=0;row<9;row++,y+=2,x = Xval+1){
		for(int col=0;col<9;col++,x+=5){
			gotoxy(x,y);
			if(maze[row][col]==0){
				printf("####");
			}
		}
	}
}
void display_start_end(){
	gotoxy(Xval-6,Yval+2);
	printf("Start");
	gotoxy(Xval+47,Yval+18);
	printf("End");
}
void start_game(int maze[9][9]){
	int row=0;
	int col=0;
	int x = Xval+2;
	int y = Yval+2;
	gotoxy(x,y);
	printf("OO");
	int key;
	while(1){
		key = getch();
		key = getch();
		switch(key){
			case LEFT :{
				if(isSafe(maze,row,col-1)){
					col--;
					gotoxy(x,y);
					printf("  ");
					x = x -5;
					gotoxy(x,y);
					printf("OO");
				}
				break;
			}
			case RIGHT :{
				if(isSafe(maze,row,col+1)){
					col++;
					gotoxy(x,y);
					printf("  ");
					x = x + 5;
					gotoxy(x,y);
					printf("OO");
				}
				break;
			}
			case UP:{
				if(isSafe(maze,row-1,col)){
					row--;
					gotoxy(x,y);
					printf("  ");
					y = y - 2;
					gotoxy(x,y);
					printf("OO");
				}
				break;
			}
			case DOWN :{
				if(isSafe(maze,row+1,col)){
					row++;
					gotoxy(x,y);
					printf("  ");
					y = y + 2;
					gotoxy(x,y);
					printf("OO");
				}
				break;
			}
		}
		if(row == 8 && col == 8){
			gotoxy(Xval+20,Yval+20);
			printf("YOU WIN");
			break;
		}
	}
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
