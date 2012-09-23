#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <queue>

#include "GameState.h"
#include "Move.cpp"

using namespace std;



void getInput(unsigned int &rows, 
              unsigned int &cols, 
              unsigned int ** &matrix);


unsigned int ** cloneMatrix(unsigned int rows, 
                            unsigned int cols, 
                            unsigned int ** &source);


void printMatrix(FILE * stream, 
                 unsigned int rows, 
                 unsigned int cols, 
                 unsigned int ** matrix);
                 
                 
void printGameState(FILE * stream, 
                    GameState * gs);


Move * doMove(unsigned int ** matrix, 
              unsigned int zeroRow, 
              unsigned int zeroCol, 
              char direction, 
              Move * prevMove);


char * getRandomMoveOrder();


#endif
