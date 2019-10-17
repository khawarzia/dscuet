#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int i1,j1,turn=0;
char character,comp_char,char1[2];
int main(void){
	void board_print(char turns[3][3]);
	void draw_check(char turns[3][3]);
	int win_check(char turns[3][3]);
	void take_turn(char turns[3][3]);
	void comp_turn(char turns[3][3]);
	char turns[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int check1=0,check2,check3;
	bool check=false;
	printf("--------MENU--------\n1 : Play with X \n2 : Play with O \nAnything else : Exit\n\nEnter the number of your choice :> ");
	if (check1 == 0){
		scanf("%d",&check1);
		if (check1 == 1){
			character = 'X';
			comp_char = 'O';
		}
		else if (check1 == 2){
			character = 'O';
			comp_char = 'X';
		}
		else {
			exit(1);
		}
	}
	system("cls");
	printf("\n\nWould you like Player 2 to be another person or the computer ?\n"
			"1 : Computer \n2 : Another person\nAnything else : Exit\n\nEnter the number of your choice :> ");
	scanf("%d",&check3);
	if (check3 == 1){
		check = false;
	}
	else if (check3 == 2){
		check = true;
	}
	else {
		exit(1);
	}
	system("cls");
	while (check == false){
		board_print(turns);
		draw_check(turns);
		take_turn(turns);
		turns[i1][j1] = character;
		system("cls");
		board_print(turns);
		check2 = win_check(turns);
		if (check2 == 1){
			printf("Player 1 wins\n");
			printf("\n\nEnter y to play again and anything else to exit : ");
			scanf("%s",&char1);
			if (char1[0] == 'y'){
				system("cls");main();
			}
			else{
				exit(1);
			}
		}
		board_print(turns);
		comp_turn(turns);
		system("cls");
		board_print(turns);
		check2 = win_check(turns);
		if (check2 == 2){
			printf("Computer wins\n");
			printf("\n\nEnter y to play again and anything else to exit : ");
			scanf("%s",&char1);
			if (char1[0] == 'y'){
				system("cls");main();
			}
			else{
				exit(1);
			}
		}
		turn++;
		system("cls");
		printf("\n\n\nComputer has taken it's turn");
	}
	while (check == true){
		board_print(turns);
		draw_check(turns);
		printf("1 Player's turn\n");
		take_turn(turns);
		turns[i1][j1] = character;
		system("cls");
		board_print(turns);
		check2 = win_check(turns);
		if (check2 == 1){
			printf("Player 1 wins\n");
			printf("\n\nEnter y to play again and anything else to exit : ");
			scanf("%s",&char1);
			if (char1[0] == 'y'){
				system("cls");main();
			}
			else{
				exit(1);
			}
		}
		printf("2 Player's turn\n");
		take_turn(turns);
		turns[i1][j1] = comp_char;
		system("cls");
		check2 = win_check(turns);
		if (check2 == 2){
			printf("Player 2 wins\n");
			printf("\n\nEnter y to play again and anything else to exit : ");
			scanf("%s",&char1);
			if (char1[0] == 'y'){
				system("cls");main();
			}
			else{
				exit(1);
			}
		}
	}	
}
void board_print(char turns[3][3]){
	printf("\n\n\n");
	for (int i=0 ; i < 3 ; i++){
		for (int j=0 ; j < 2 ; j++){
			printf("        |");
		}
		printf("\n");
		for (int j=0 ; j < 3 ; j++){
			if (j != 2){
				printf("    %c   |",turns[i][j]);
			}
			else {
				printf("    %c",turns[i][j]);
			}
		}
		printf("\n");
		if (i != 2){
			for (int k=0 ; k < 26 ; k++){
			printf("-");
			}
		}
		printf("\n");
	}
}
void draw_check(char turns[3][3]){
	int count=0;
	for (int i=0 ; i < 3 ; i++){
		for (int j=0 ; j < 3 ; j++){
			if (turns[i][j] != ' '){
				count++;
			}
		}
	}
	if (count == 9){
		printf("\nThe game is a draw.");
		printf("\n\nEnter y to play again and anything else to exit : ");
			scanf("%s",&char1);
			if (char1[0] == 'y'){
				main();
			}
			else{
				exit(1);
			}
	}
}
int win_check(char turns[3][3]){
	int count=0;
	if (turns[0][0]== character && turns[1][1]== character && turns[2][2]== character){
		return 1;
	}
	else if (turns[0][2]== character && turns[1][1]== character && turns[2][0]== character){
		return 1;
	}
	else if (turns[0][1]== character && turns[1][1]== character && turns[2][1]== character){
		return 1;
	}
	else if (turns[1][0]== character && turns[1][1]== character && turns[1][2]== character){
		return 1;
	}
	else if (turns[0][0]== character && turns[0][1]== character && turns[0][2]== character){
		return 1;
	}
	else if (turns[0][0]== character && turns[1][0]== character && turns[2][0]== character){
		return 1;
	}
	else if (turns[2][2]== character && turns[2][1]== character && turns[2][0]== character){
		return 1;
	}
	else if (turns[0][2]== character && turns[1][2]== character && turns[2][2]== character){
		return 1;
	}
	else if (turns[0][0]== comp_char && turns[1][1]== comp_char && turns[2][2]== comp_char){
		return 2;
	}
	else if (turns[0][2]== comp_char && turns[1][1]== comp_char && turns[2][0]== comp_char){
		return 2;
	}
	else if (turns[0][1]== comp_char && turns[1][1]== comp_char && turns[2][1]== comp_char){
		return 2;
	}
	else if (turns[1][0]== comp_char && turns[1][1]== comp_char && turns[1][2]== comp_char){
		return 2;
	}
	else if (turns[0][0]== comp_char && turns[0][1]== comp_char && turns[0][2]== comp_char){
		return 2;
	}
	else if (turns[0][0]== comp_char && turns[1][0]== comp_char && turns[2][0]== comp_char){
		return 2;
	}
	else if (turns[2][2]== comp_char && turns[2][1]== comp_char && turns[2][0]== comp_char){
		return 2;
	}
	else if (turns[0][2]== comp_char && turns[1][2]== comp_char && turns[2][2]== comp_char){
		return 2;
	}
}
void take_turn(char turns[3][3]){
	char turn_pos[2];
	printf("Your Turn :> ");
	scanf("%s",turn_pos);
	if (turn_pos[0] == '1' && turns[0][0] == ' '){
		i1 = 0;
		j1 = 0;
	}
	else if (turn_pos[0] == '2' && turns[0][1] == ' '){
		i1 = 0;
		j1 = 1;
	}
	else if (turn_pos[0] == '3' && turns[0][2] == ' '){
		i1 = 0;
		j1 = 2;
	}
	else if (turn_pos[0] == '4' && turns[1][0] == ' '){
		i1 = 1;
		j1 = 0;
	}
	else if (turn_pos[0] == '5' && turns[1][1] == ' '){
		i1 = 1;
		j1 = 1;
	}
	else if (turn_pos[0] == '6' && turns[1][2] == ' '){
		i1 = 1;
		j1 = 2;
	}
	else if (turn_pos[0] == '7' && turns[2][0] == ' '){
		i1 = 2;
		j1 = 0;
	}
	else if (turn_pos[0] == '8' && turns[2][1] == ' '){
		i1 = 2;
		j1 = 1;
	}
	else if (turn_pos[0] == '9' && turns[2][2] == ' '){
		i1 = 2;
		j1 = 2;
	}
	else {
		printf("Enter a valid location please. \n");
		take_turn(turns);
	}
}
void comp_turn(char turns[3][3]){
	char turns_copy[3][3];
	int a;
	for (int i=0 ; i < 3 ; i++){
		for (int j=0 ; j < 3 ; j++){
			a = turns[i][j];
			turns_copy[i][j] = a;
		}
	}
	if (turns[1][1] == ' '){
		turns[1][1] = comp_char;
	}
	else {
		turns[0][0] = comp_char;
	}
	if (turn >= 1){
		int check;
		for (int i=0 ; i < 3 ; i++){
			for (int j=0 ; j < 3 ; j++){
				if (turns_copy[i][j] == ' '){
					turns_copy[i][j] = comp_char;
					check = win_check(turns_copy);
					if (check == 2){
						turns[i][j] = comp_char;
						return ;
					}
					turns_copy[i][j] = ' ';
					check = 0;
				}
			}
		}
		for (int i=0 ; i < 3 ; i++){
			for (int j=0 ; j < 3 ; j++){
				if (turns_copy[i][j] == ' '){
					turns_copy[i][j] = character;
					check = win_check(turns_copy);
					if (check == 1){
						turns[i][j] = comp_char;
						return ;
					}
					turns_copy[i][j] = ' ';
					check = 0;
				}
			}
		}
		if (turns[0][1] == ' '){
			turns[0][1] = comp_char;
			return ;
		}
		else if (turns[2][2] == ' '){
			turns[2][2] = comp_char;
		}
		else if (turns[0][2] == ' '){
			turns[0][2] = comp_char;
		}
	}
}
