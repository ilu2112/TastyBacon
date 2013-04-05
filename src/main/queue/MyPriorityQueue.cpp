#include "MyPriorityQueue.h"


MyPriorityQueue::MyPriorityQueue() {
}


short MyPriorityQueue::evaluate(Move * move) {
    short result = 0;
    unsigned int ** actualState = move->actualState->getAsArray();
    unsigned int ** targetState = GameState::getFinalGameState()->getAsArray();
    for (unsigned int i=0; i<GameState::rows; i++) {
        for (unsigned int j=0; j<GameState::cols; j++) {
            if (actualState[i][j] != targetState[i][j]) {
                // corners (+4)
                if ( (i == 0 && j == 0) || 
                   (i == 0 && j == GameState::cols - 1) ||
                   (i == GameState::rows - 1 && j == GameState::cols - 1) ||
                   (i == GameState::rows - 1 && j == 0) ) {
                        result += 4;
                } else if (i == 0 || i == GameState::rows - 1 || j == 0 || j == GameState::cols - 1) {
                    // sides (+2)
                    result += 2;
                } else {
                    result += 1;
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
