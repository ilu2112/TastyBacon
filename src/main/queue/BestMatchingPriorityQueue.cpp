#include "BestMatchingPriorityQueue.h"
#include "AbstractPriorityQueue.h"


BestMatchingPriorityQueue::BestMatchingPriorityQueue() {
}


short BestMatchingPriorityQueue::evaluate(Move * move) {
    short result = 0;
    unsigned int ** actualState = move->actualState->getAsArray();
    unsigned int ** targetState = GameState::getFinalGameState()->getAsArray();
    for (unsigned int i=0; i<GameState::rows; i++) {
        for (unsigned int j=0; j<GameState::cols; j++) {
            if (actualState[i][j] != targetState[i][j]) {
                ++result;
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
