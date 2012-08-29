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

	
unsigned int** GameState::getAsArray(long long int state) {
	unsigned int **result = new unsigned int*[GameState::rows];
	long long int base = 0xF;
	int counter = 0;
	for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
		result[iRow] = new unsigned int[GameState::cols];
		for(unsigned int iCol = 0; iCol < GameState::cols; iCol++) {
			result[iRow][iCol] = (state & (base << (60 - 4*counter))) >> (60 - 4*counter); 
			++counter;
		}
	}
	return result;
}


unsigned int** GameState::getAsArray() {
	return GameState::getAsArray(this->state);
}


long long int GameState::getAsInt() {
	return this->state;
}


bool GameState::operator==(const GameState &gs) const {
	return this->state == gs.state;
}


GameState *GameState::getFinalGameState(unsigned int rows, unsigned int cols) {
	unsigned int counter = 1;
	unsigned int capacity = rows * cols;
	unsigned int **matrix = new unsigned int*[rows];
	for(unsigned int iRow = 0; iRow < rows; iRow++) {
		matrix[iRow] = new unsigned int[cols];
		for(unsigned int iCol = 0; iCol < cols; iCol++) {
			matrix[iRow][iCol] = counter; 
			counter = (counter + 1)%capacity;
		}
	}
	return new GameState(GameState::getAsInt(matrix, rows, cols));
}