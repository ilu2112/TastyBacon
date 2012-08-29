#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <queue>
#include "GameState.h"
#include "Move.cpp"

using namespace std;

void getInput(unsigned int &rows, 
              unsigned int &cols, 
              unsigned int **&matrix);

unsigned int **cloneMatrix(unsigned int rows, 
                           unsigned int cols, 
                           unsigned int **&source);

void printMatrix(FILE *stream, 
                 unsigned int rows, 
                 unsigned int cols, 
                 unsigned int **matrix);
                 
void printGameState(FILE *stream, 
                   GameState *gs);


void moveLeft(unsigned int**matrix, 
              unsigned int zeroRow, 
              unsigned int zeroCol,
              Move* prevMove,
              queue<Move*> *moveQueue);


void moveRight(unsigned int**matrix, 
               unsigned int zeroRow, 
               unsigned int zeroCol, 
               Move* prevMove,
               queue<Move*> *moveQueue);


void moveDown(unsigned int**matrix, 
              unsigned int zeroRow, 
              unsigned int zeroCol,
              Move* prevMove, 
              queue<Move*> *moveQueue);


void moveUp(unsigned int**matrix, 
            unsigned int zeroRow, 
            unsigned int zeroCol, 
            Move* prevMove,
            queue<Move*> *moveQueue);


#endif
