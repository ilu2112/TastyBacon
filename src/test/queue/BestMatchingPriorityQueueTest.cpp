#include <stdio.h>
#include <algorithm>
#include "../../main/utils/GameState.h"
#include "../../main/utils/Move.cpp"
#include "../../main/queue/BestMatchingPriorityQueue.h"



int main() {
    
    // TEST 1
    //  1   2   3   4
    //  5   6   7   8
    //  9   10  11  12
    //  13  14  15  0
    // answer: 0
    unsigned int val = 1;
    unsigned int ** matrix;
    matrix = new unsigned int*[4];
    for (int iRow = 0; iRow < 4; iRow++) {
        matrix[iRow] = new unsigned int[4];
        for (int iCol = 0; iCol < 4; iCol++) {
            matrix[iRow][iCol] = val++;
        }
    }
    matrix[3][3] = 0;
    GameState::setSize(4, 4);
    GameState * gs = new GameState(matrix);
    Move * move = new Move(gs, NULL, 'D');
    printf("%hd\n", (new BestMatchingPriorityQueue())->evaluate(move));
    
    // TEST 2
    //  0   2   3   4
    //  5   11   7   8
    //  9   10  6  12
    //  13  14  15  1
    // answer: 4
    std::swap(matrix[0][0], matrix[3][3]);
    std::swap(matrix[1][1], matrix[2][2]);
    delete gs;
    delete move;
    gs = new GameState(matrix);
    move = new Move(gs, NULL, 'D');
    printf("%hd\n", (new BestMatchingPriorityQueue())->evaluate(move));
}
