#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "GameState.h"

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

#endif
