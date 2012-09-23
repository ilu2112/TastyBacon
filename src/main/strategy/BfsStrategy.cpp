//  BFS Strategy with FIFO queue.

#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "BfsStrategy.h"
#include "../utils/GameState.h"
#include "../utils/Move.cpp"
#include "../utils/utils.h"

using namespace std;



BfsStrategy::BfsStrategy(char * order) {
    this->order = new char[strlen(order)];
    for (unsigned int i = 0; i < strlen(order); i++) {
        this->order[i] = order[i];
    }
}


char * BfsStrategy::solve(GameState * state, const char * storageFileName) {

    // create a set of visited states and a FIFO queue
    set<GameState *, GameState::Comparator> * visitedStates = new set<GameState *, GameState::Comparator>();
    queue<Move *> * moveQueue = new queue<Move *>();

    // initial values
    moveQueue->push(new Move(state, NULL, 'X'));

    // get final state
    GameState * finalState = GameState::getFinalGameState();

    // stack for final steps (result)
    stack<char> finalSteps;
    
    // start solving
    do {
        // get next state
        Move * move = moveQueue->front();
        moveQueue->pop();

        // check if we have a visited state
        if (visitedStates->find(move->actualState) != visitedStates->end()) {
            continue;
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
