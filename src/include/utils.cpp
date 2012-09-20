#include <stdio.h>
#include <queue>
#include <algorithm>
#include <time.h>
#include "GameState.h"
#include "Move.cpp"

using namespace std;

void getInput(unsigned int &rows, unsigned int &cols, unsigned int **&matrix) {
    scanf("%u %u\n", &rows, &cols);
    matrix = new unsigned int*[rows];
    for(unsigned int iRow = 0; iRow < rows; iRow++) {
        matrix[iRow] = new unsigned int[cols];
        for(unsigned int iCol = 0; iCol < cols; iCol++) {
            scanf("%u", &matrix[iRow][iCol]);
        }
    }
}


unsigned int **cloneMatrix(unsigned int &rows, unsigned int &cols, unsigned int **&source) {
    unsigned int **clone = new unsigned int*[rows];
    for(int unsigned iRow = 0; iRow < rows; iRow++) {
        clone[iRow] = new unsigned int[cols];
        for(int unsigned iCol = 0; iCol < cols; iCol++) {
            clone[iRow][iCol] = source[iRow][iCol];
        }
    }
    return clone;
}


void printMatrix(FILE *stream, unsigned int rows, unsigned int cols, unsigned int **matrix) {
    for(unsigned int iRow = 0; iRow < rows; iRow++) {
        for(unsigned int iCol = 0; iCol < cols; iCol++) {
            fprintf(stream, "%5u", matrix[iRow][iCol]);
        }
        fprintf(stream, "\n");
    }
}


void printGameState(FILE *stream, GameState *gs) {
    printMatrix(stream, gs->rows, gs->cols, gs->getAsArray());
}


void moveLeft(unsigned int**matrix, unsigned int zeroRow, unsigned int zeroCol, Move* prevMove, 
              queue<Move*> *moveQueue) {
    if(zeroCol > 0) {
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow][zeroCol-1]);
        moveQueue->push(new Move( new GameState(matrix), prevMove, 'L'));
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow][zeroCol-1]);
    }
}


void moveRight(unsigned int**matrix, unsigned int zeroRow, unsigned int zeroCol, Move* prevMove, 
              queue<Move*> *moveQueue) {
    if(zeroCol < GameState::cols - 1) {
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow][zeroCol+1]);
        moveQueue->push(new Move( new GameState(matrix), prevMove, 'P'));
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow][zeroCol+1]);
    }
}


void moveDown(unsigned int**matrix, unsigned int zeroRow, unsigned int zeroCol, Move* prevMove, 
              queue<Move*> *moveQueue) {
    if(zeroRow < GameState::rows - 1) {
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow+1][zeroCol]);
        moveQueue->push(new Move( new GameState(matrix), prevMove, 'D'));
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow+1][zeroCol]);
    }
}


void moveUp(unsigned int**matrix, unsigned int zeroRow, unsigned int zeroCol, Move* prevMove, 
              queue<Move*> *moveQueue) {
    if(zeroRow > 0) {
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow-1][zeroCol]);
        moveQueue->push(new Move( new GameState(matrix), prevMove, 'G'));
        std::swap(matrix[zeroRow][zeroCol], matrix[zeroRow-1][zeroCol]);
    }
}


char *getRandomMoveOrder() {
    char *result = new char[4];
    result[0] = 'G';
    result[1] = 'D';
    result[2] = 'L';
    result[3] = 'P';
    srand( time(NULL) );
    for(int i=0; i<10; i++) {
        swap(result[random() % 4], result[random() % 4]);
    }
    return result;
}
