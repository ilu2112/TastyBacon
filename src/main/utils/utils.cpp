#include <algorithm>
#include <queue>
#include <stdio.h>
#include <time.h>

#include "GameState.h"
#include "Move.cpp"

using namespace std;



void getInput(unsigned int &rows, unsigned int &cols, unsigned int ** &matrix) {
    scanf("%u %u\n", &rows, &cols);
    matrix = new unsigned int*[rows];
    for (unsigned int iRow = 0; iRow < rows; iRow++) {
        matrix[iRow] = new unsigned int[cols];
        for (unsigned int iCol = 0; iCol < cols; iCol++) {
            scanf("%u", &matrix[iRow][iCol]);
        }
    }
}


unsigned int ** cloneMatrix(unsigned int &rows, unsigned int &cols, unsigned int ** &source) {
    unsigned int ** clone = new unsigned int*[rows];
    for (int unsigned iRow = 0; iRow < rows; iRow++) {
        clone[iRow] = new unsigned int[cols];
        for (int unsigned iCol = 0; iCol < cols; iCol++) {
            clone[iRow][iCol] = source[iRow][iCol];
        }
    }
    return clone;
}


void printMatrix(FILE * stream, unsigned int rows, unsigned int cols, unsigned int ** matrix) {
    for (unsigned int iRow = 0; iRow < rows; iRow++) {
        for (unsigned int iCol = 0; iCol < cols; iCol++) {
            fprintf(stream, "%5u", matrix[iRow][iCol]);
        }
        fprintf(stream, "\n");
    }
}


void printGameState(FILE * stream, GameState * gs) {
    fprintf(stream, "%d %d\n", GameState::rows, GameState::cols);
    printMatrix(stream, gs->rows, gs->cols, gs->getAsArray());
}


Move * doMove(unsigned int ** matrix, unsigned int zeroRow, unsigned int zeroCol, char direction, Move * prevMove) {
    int newRow = zeroRow;
    int newCol = zeroCol;
    switch (direction) {
        case 'D':
            ++newRow;
            break;
        case 'G':
            --newRow;
            break;
        case 'L':
            --newCol;
            break;
        case 'P':
            ++newCol;
            break;
    }

    Move * move = NULL;
    if (newCol >= 0 && newRow >= 0 && newCol < GameState::cols && newRow < GameState::rows) {
        std::swap(matrix[zeroRow][zeroCol], matrix[newRow][newCol]);
        move = new Move( new GameState(matrix), prevMove, direction);
        std::swap(matrix[zeroRow][zeroCol], matrix[newRow][newCol]);
    }

    return move;
}


char * getRandomMoveOrder() {
    char * result = new char[4];
    result[0] = 'G';
    result[1] = 'D';
    result[2] = 'L';
    result[3] = 'P';
    srand( time(NULL) );
    for (int i=0; i<10; i++) {
        swap(result[random() % 4], result[random() % 4]);
    }
    return result;
}
