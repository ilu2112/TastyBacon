#include "include/utils.h"
#include "include/AbstractStrategy.h"
#include "include/BfsStrategy.h"
#include "include/GameState.h"
#include <stdio.h>
#include <set>
using namespace std;

int main(int argc, char **argv) {
    unsigned int rows;
    unsigned int cols; 
    unsigned int **matrix;
    getInput(rows, cols, matrix);
    printMatrix(stdout, rows, cols, matrix);
    
    GameState::setSize(rows, cols);
    GameState *gs = new GameState(matrix);
        
    char order[] = {'A', 'B', 'C', 'X'};
    AbstractStrategy *strategy = new BfsStrategy(order);
    printf("%s\n", strategy->solve(gs, "ciotka"));
    
    return 0;
}
