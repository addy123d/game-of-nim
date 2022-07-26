#include <stdlib.h>
#include <stdio.h>

void swapPlayers();
void flushInput();

int player = 1;

int main() {
	char *endptr;
	int gameState = 1;
	int row1 = 1;
	int row2 = 3;
	int row3 = 5;
	int row4 = 7;
	int i = 0;
	long rowIN;
	long numIN;
	long rowVal;
	long numVal;
	int validMove = 0;

	/* Print Game State */
	while(gameState) {
		printf("1| ");
		for(i = 0; i < row1; i++) {
			printf("O ");
		}
		printf("\n2| ");
		for(i = 0; i < row2; i++) {
			printf("O ");
		}
		printf("\n3| ");
		for(i = 0; i < row3; i++) {
			printf("O ");
		}
		printf("\n4| ");
		for(i = 0; i < row4; i++) {
			printf("O ");
		}
		printf("\n +");
		for (i = 0; i < 20; i++) {
			printf("-");
		}
		printf("\n   ");
		i = 1;
		while (i < 8) {
			printf("%d ", i);
			i++;
		}
		printf("\n");

		/* Moves */
		validMove = 0;
		while (!validMove) {
			/* Get Moves */
			printf("\n");
			printf("Player %d move: ", player);
			if (scanf("%s%s", &rowIN, &numIN) != 2) {
				printf("error: must enter two integers, seperated by a space\n");
				continue;
			}
			printf("\n");
			// check move
			rowVal = strtol(&rowIN, &endptr, 10);
			if(*endptr != '\0') {
				printf("first argument incorrect: must be valid positive integer.\n");
				flushInput();
				continue;
			}
			numVal = strtol(&numIN, &endptr, 10);
			if(*endptr != '\0') {
				printf("second argument incorrect: must be valid positive integer.\n");
				flushInput();
				continue;
			}

			// resignation move
			if((rowVal == 0) && (numVal == 0)) {
				validMove = 1;
				printf("Player %d resigns. ", player);
				swapPlayers();
				printf("Player %d wins!\n", player);
				exit(0);
			}

			if ((rowVal < 0) || (rowVal > 4)) {
				printf("Invalid row selection.\n");
				continue;
			}
			if ((numVal < 1) || (numVal > 7)) {
				printf("Invalid number of stones to remove\n");
				continue;
			}

			switch(rowVal) {
				case 1:
					if (numVal <= row1) {
						row1 -= numVal;
						validMove = 1;
					} else {
						printf("error: cannot remove more stones than present\n");
					}
					break;
				case 2:
					if (numVal <= row2) {
						row2 -= numVal;
						validMove = 1;
					} else {
						printf("error: cannot remove more stones than present\n");
					}
					break;
				case 3:
					if (numVal <= row3) {
						row3 -= numVal;
						validMove = 1;
					} else {
						printf("error: cannot remove more stones than present\n");
					}
					break;
				case 4:
					if (numVal <= row4) {
						row4 -= numVal;
						validMove = 1;
					} else {
						printf("error: cannot remove more stones than present\n");
					}
					break;
				default:
					printf("Invalid row\n"); //execution should not reach
			}
			//validMove = 1;
		}




		/* Check for Game Over */
		if ((row1 == 0) && (row2 == 0) && (row3 == 0) && (row4 == 0)) {
			swapPlayers();
			printf("Player %d wins!\n", player);
			return;
		}

		/* Swap Players */
		swapPlayers();

	}

	return; // execution should never reach this point
}

void swapPlayers() {
	if(player == 1) {
		player = 2;
	} else {
		player = 1;
	}
}

void flushInput() {
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}
