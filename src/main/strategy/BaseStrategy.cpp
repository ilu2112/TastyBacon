// Pass FifoQueue as AbstractQueue in contructor to get BFS Strategy.
// Pass LifoQueue as AbstractQueue in contructor to get DFS Strategy.

#include <algorithm>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>

#include "BaseStrategy.h"
#include "../utils/GameState.h"
#include "../utils/Move.cpp"
#include "../utils/utils.h"

using namespace std;


BaseStrategy::BaseStrategy(char * order, AbstractMoveQueue * moveQueue, unsigned int maxDepth) {
    this->order = new char[strlen(order)];
    for (unsigned int i = 0; i < strlen(order); i++) {
        this->order[i] = order[i];
    }
    this->moveQueue = moveQueue;
    this->maxDepth = maxDepth;
}


char * BaseStrategy::solve(GameState * state, const char * storageFileName) {

    // create a set of visited states
    set<GameState *, GameState::Comparator> * visitedStates = new set<GameState *, GameState::Comparator>();

    // initial values
    moveQueue->push(new Move(state, NULL, 'X'));

    // get final state
    GameState * finalState = GameState::getFinalGameState();

    // stack for final steps (result)
    stack<char> finalSteps;

    // start solving
    do {
        // get next state
        Move * move = moveQueue->next();
        moveQueue->pop();

        // check if recursion depth is too high
        if (move->recursionDepth > this->maxDepth) {
            continue;
        }

        // check if we have a visited state
        if (visitedStates->find(move->actualState) != visitedStates->end()) {
            continue;
        } else {
            visitedStates->insert(move->actualState);
        }

        // print actual status to the specified file
        FILE * storageFile = fopen(storageFileName, "w");
        if (storageFile != NULL) {
            printGameState(storageFile, move->actualState);
            fclose(storageFile);
        }

        // check if it is done
        if ( *(move->actualState) == *finalState) {
            while (move->prevMove != NULL) {
                finalSteps.push(move->movement);
                move = move->prevMove;
            }
            break;
        }

        unsigned int ** matrix = move->actualState->getAsArray();

        // find '0'
        for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
            for(unsigned int iCol = 0; iCol < GameState::cols; iCol++) {
                if(matrix[iRow][iCol] == 0) {
                    // find the right movement order
                    char * order;
                    if (this->order[0] == 'R') {
                        order = getRandomMoveOrder();
                    } else {
                        order = this->order;
                    }
                    //  process all moves
                    for (int i=0; i<4; i++) {
                        Move * nextMove = doMove(matrix, iRow, iCol, order[i], move);
                        if (nextMove != NULL) {
                            moveQueue->push(nextMove);
                        }
                    }
                }
            }
        }

        // clean-up
        for (unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
            delete[] matrix[iRow];
        }
        delete[] matrix;

        // check if we have no more moves
        if (moveQueue->isEmpty()) {
            break;
        }

    } while(true);

    // form a result
    char * result;
    if (finalSteps.size() > 0) {
        result = new char[finalSteps.size() + 1];
        result[finalSteps.size()] = 0;
        unsigned int count = 0;
        while (!finalSteps.empty()) {
            result[count++] = finalSteps.top();
            finalSteps.pop();
        }
    } else {
        result = new char[2];
        result[0] = 'X';
        result[1] = 0;
    }

    return result;
}
