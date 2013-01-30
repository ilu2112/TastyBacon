#include "utils/utils.h"
#include "strategy/AbstractStrategy.h"
#include "strategy/BaseStrategy.h"
#include "queue/FifoMoveQueue.h"
#include "queue/LifoMoveQueue.h"
#include "utils/Move.cpp"
#include "utils/GameState.h"
#include <stdio.h>
#include <set>

using namespace std;

int main(int argc, char **argv) {
    unsigned int rows;
    unsigned int cols;
    unsigned int **matrix;
    getInput(rows, cols, matrix);
    // printMatrix(stdout, rows, cols, matrix);

    GameState::setSize(rows, cols);
    GameState *gs = new GameState(matrix);

    char order[] = {'L', 'G', 'P', 'D', 0};
    // AbstractStrategy *strategy = new BfsStrategy(order);
    AbstractStrategy *strategy = new BaseStrategy(order, new LifoMoveQueue());
    printf("%s\n", strategy->solve(gs));

    return 0;
}
