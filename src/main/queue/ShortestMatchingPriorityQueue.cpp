#include "ShortestMatchingPriorityQueue.h"


ShortestMatchingPriorityQueue::ShortestMatchingPriorityQueue() {
}


short ShortestMatchingPriorityQueue::evaluate(Move * move) {
    short result = 0;
    unsigned int ** actualState = move->actualState->getAsArray();
    unsigned int ** targetState = GameState::getFinalGameState()->getAsArray();
    // for each block
    for (unsigned int i=0; i<GameState::rows; i++) {
        for (unsigned int j=0; j<GameState::cols; j++) {
            // find its place in the second state
            for (unsigned int i2=0; i2<GameState::rows; i2++) {
                for (unsigned int j2=0; j2<GameState::cols; j2++) {
                    if (actualState[i][j] == targetState[i2][j2]) {
                        result = result + (i>i2?i-i2:i2-i) + (j>j2?j-j2:j2-j);
                    }
                }
            }
        }
    }
    // clean up
    for (unsigned int i=0; i<GameState::rows; i++) {
        delete [] actualState[i];
    }
    delete [] actualState;

    return result;
}
