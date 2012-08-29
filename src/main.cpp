#include "include/utils.h"
#include "include/AbstractStrategy.h"
#include "include/BfsStrategy.h"
#include "include/GameState.h"
#include <stdio.h>

int main(int argc, char **argv) {
	unsigned int rows;
	unsigned int cols; 
	unsigned int **matrix;
	getInput(rows, cols, matrix);
	printMatrix(stdout, rows, cols, matrix);
	
	GameState::setSize(rows, cols);
	GameState *gs = new GameState( GameState::getAsInt(matrix, rows, cols));
	
	char order[] = {'A', 'B', 'C', 'X'};
	AbstractStrategy *strategy = new BfsStrategy(order);
	printf("%s\n", strategy->solve(gs, stdout));
	
	printf("%d\n", sizeof(*gs));
	
	GameState::setSize(4, 4);
	printGameState( stdout, GameState::getFinalGameState(4, 4));
	
	printf("%d\n", (int)(*gs == *GameState::getFinalGameState(4, 4)));
	printf("%d\n", (int)(*gs == *gs));
	
	return 0;
}
