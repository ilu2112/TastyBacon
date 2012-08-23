#include "include/utils.h"

int main(int argc, char **argv) {
	unsigned int rows;
	unsigned int cols; 
	unsigned int **matrix;
	getInput(rows, cols, matrix);
	printMatrix(stdout, rows, cols, matrix);
	return 0;
}
