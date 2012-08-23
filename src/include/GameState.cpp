#include "GameState.h"

unsigned int GameState::rows = 0;
unsigned int GameState::cols = 0;

GameState::GameState(long long int state) {
	this->state = state;
}


void GameState::setSize(unsigned int rows, unsigned int cols) {
	GameState::rows = rows;
	GameState::cols = cols;
}
	

long long int GameState::getAsInt(unsigned int **array, unsigned int rows, unsigned int cols) {
	long long int result = 0;
	for(unsigned int iRow = 0; iRow < rows; iRow++) {
		for(unsigned int iCol = 0; iCol < cols; iCol++) {
			result <<= 4;
			result += array[iRow][iCol];
		}
	}
	result <<= 4*(16-rows*cols);
	return result;
}

	
unsigned int** GameState::getAsArray() {
	unsigned int **result = new unsigned int*[GameState::rows];
	long long int base = 0xF;
	int counter = 0;
	for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
		result[iRow] = new unsigned int[GameState::cols];
		for(unsigned int iCol = 0; iCol < GameState::cols; iCol++) {
			result[iRow][iCol] = (this->state & (base << (60 - 4*counter))) >> (60 - 4*counter); 
			++counter;
		}
	}
	return result;
}

