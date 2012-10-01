#include <stdio.h>
#include "../../main/utils/GameState.h"
#include "../../main/utils/utils.h"


int main() {

    // make game state
    unsigned int val = 15;
    unsigned int ** matrix;
    matrix = new unsigned int*[4];
    for (int iRow = 0; iRow < 4; iRow++) {
        matrix[iRow] = new unsigned int[4];
        for (int iCol = 0; iCol < 4; iCol++) {
            matrix[iRow][iCol] = val--;
        }
    }
    GameState::setSize(4, 4);
    GameState * gs = new GameState(matrix);

    printf("%llu\n", gs->getAsInt());
    printGameState(stdout, gs);

    return 0;
}
