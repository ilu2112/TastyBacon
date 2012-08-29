#include <stdio.h>
#include "GameState.h"

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
