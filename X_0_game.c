#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int row = 3;
const int col = 3;
	
// Filling with ' - '
void fill (int array[row+1][col+1]) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			array[i][j] = '-';
		}
	}	
}
// Printing for every time
void print (int array[row+1][col+1]) {
	printf("\n ");
	for (int i = 1; i <= col; i++) printf("%4d", i);
	puts("");
	for (int i = 1; i <= row; i++) {
		printf("\n%d", i);
		for (int j = 1; j <= col; j++) {
			printf("%4c", array[i][j]);
		}
		puts("");
	}	
}
// If first player wins
void fplayer () {
	printf("CONGRATULATIONS! YOU WON!\n");	
}
// If computer wins 
void computer () {
	printf("SORRY! YOU LOST!\n");
}
// If second player wins 
void splayer () {
	printf("CONGRATULATIONS! SECOND PLAYER WON!\n");	
}
// Game Function	
void game_X_0 (int array[row+1][col+1]) {
	srand(time(0));
	printf("Do you want to play with Computer or Friend?\nComputer -> Enter 1 || Friend -> Enter 0 >>> ");
	system("clear");
	int choice; scanf("%d", &choice); 	
	if (choice == 1) {
		system("clear");
		printf("Who starts with X\nYou -> 1 || Computer -> 0 >>> ");
		int select; scanf("%d", &select);
		if (select == 1) {
			print(array);
			do {
				int x, y;
				int a, b;
				while (1) {
					label :
					printf("Select location of X : ");
					scanf("%d %d", &x, &y);
					if (array[x][y]==88) {
						printf("YOU'VE ALREADY FILLED THIS LOCATION!\nPLEASE TRY AGAIN.\n");
						goto label;	
					}
					if (array[x][y]=='-') {
 						array[x][y] = 88;
						break;
					}
				}
				system("clear");
				print(array); 
				if (array[1][1]==88 && array[1][2]==88 && array[1][3]==88) { fplayer(); break; }
				else if (array[1][1]==88 && array[2][1]==88 && array[3][1]==88) { fplayer(); break; }
				else if (array[2][1]==88 && array[2][2]==88 && array[2][3]==88) { fplayer(); break; }
                                else if (array[1][2]==88 && array[2][2]==88 && array[3][2]==88) { fplayer(); break; }
                                else if (array[3][1]==88 && array[3][2]==88 && array[3][3]==88) { fplayer(); break; }
                                else if (array[1][3]==88 && array[2][3]==88 && array[3][3]==88) { fplayer(); break; }
       				while (1) {
					a = rand()%3 + 1;
					b = rand()%3 + 1;
					if (a!=x && b!=y && array[a][b]=='-') {	
						array[a][b] = 48;
						break;
					}	
				}
				system("clear");
				print(array);
				if (array[1][1]==88 && array[1][2]==88 && array[1][3]==88) { fplayer(); break; }
                                else if (array[1][1]==48 && array[2][1]==48 && array[3][1]==48) { computer(); break; }
                                else if (array[2][1]==48 && array[2][2]==48 && array[2][3]==48) { computer(); break; }
                                else if (array[1][2]==48 && array[2][2]==48 && array[3][2]==48) { computer(); break; }
                                else if (array[3][1]==48 && array[3][2]==48 && array[3][3]==48) { computer(); break; }
                                else if (array[1][3]==48 && array[2][3]==48 && array[3][3]==48) { computer(); break; }
			} while (1);
		}			
	}
	else if (choice == 0) {
		system("clear");
		printf("Who starts with X\nYou -> 1 || Your friend -> 0 >>> ");
		int select; scanf("%d", &select);
		if (select == 1) {
			print(array);
			do {
				int x, y;
				int a, b;
				while (1) {
					label1 :
					printf("Select location of X : ");
					scanf("%d %d", &x, &y);
					if (array[x][y]==88) {
                                                printf("YOU'VE ALREADY FILLED THIS LOCATION!\nPLEASE TRY AGAIN.\n");
                                                goto label1;
                               		}
					if (array[x][y]=='-') {
						array[x][y] = 88;
						break;
					}
				}
				system("clear");
				print(array); 
				if (array[1][1]==88 && array[1][2]==88 && array[1][3]==88) { fplayer(); break; }
				else if (array[1][1]==88 && array[2][1]==88 && array[3][1]==88) { fplayer(); break; }
				else if (array[2][1]==88 && array[2][2]==88 && array[2][3]==88) { fplayer(); break; }
                                else if (array[1][2]==88 && array[2][2]==88 && array[3][2]==88) { fplayer(); break; }
                                else if (array[3][1]==88 && array[3][2]==88 && array[3][3]==88) { fplayer(); break; }
                                else if (array[1][3]==88 && array[2][3]==88 && array[3][3]==88) { fplayer(); break; }
				while (1) {
                                        label2 :
					printf("Select location of X : ");
                                        scanf("%d %d", &a, &b);
					if (array[a][b]==48) {
                                                printf("YOU'VE ALREADY FILLED THIS LOCATION!\nPLEASE TRY AGAIN.\n");
                                                goto label2;
                              		}
                                        if (array[a][b]=='-') {
                                                array[a][b] = 48;
                                                break;
                                        }
                                }
				system("clear");
				print(array);
				if (array[1][1]==88 && array[1][2]==88 && array[1][3]==88) { fplayer(); break; }
                                else if (array[1][1]==48 && array[2][1]==48 && array[3][1]==48) { splayer(); break; }
                                else if (array[2][1]==48 && array[2][2]==48 && array[2][3]==48) { splayer(); break; }
                                else if (array[1][2]==48 && array[2][2]==48 && array[3][2]==48) { splayer(); break; }
                                else if (array[3][1]==48 && array[3][2]==48 && array[3][3]==48) { splayer(); break; }
                                else if (array[1][3]==48 && array[2][3]==48 && array[3][3]==48) { splayer(); break; }
			} while (1);
		}		
	}
	else {
		printf("INCORRECT INPUT!\n");
	}
}
int main () {
	int array[row+1][col+1];
	char choice;
	JUMP :
	printf("Do you want to play X_0 game now?\nYes -> y ||  No -> n >>> ");
	scanf("%c", &choice);
	switch (choice) {
		case 'y':
			fill(array);
			game_X_0(array);	
			break;
		case 'n':
			return 0;
		default:
			printf("INCORRECT INPUT!\n");
			goto JUMP;
	}
	int c = getchar();
	printf("Do you want to play again?\nYes -> y || No -> n >>> "); 
	char choice1; scanf("%c", &choice1);
	getchar();
	while (1) {
		switch (choice1) {
			case 'y':
				goto JUMP;
				break;
			case 'n':
				return 0;
			default: 
				printf("INCORRECT INPUT!\n");
		}
	}	
}
