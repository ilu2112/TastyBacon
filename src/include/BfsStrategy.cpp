//  BFS Strategy with FIFO queue.

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#include "BfsStrategy.h"
#include "GameState.h"
#include "utils.h"
#include "Move.cpp"

using namespace std;


BfsStrategy::BfsStrategy(char *order) {
    this->order = new char[ strlen(order) ];
    for(unsigned int i = 0; i < strlen(order); i++) {
        this->order[i] = order[i];
    }
}


char *BfsStrategy::solve(GameState *state, const char *storageFileName) {

    // create a set of visited states and a FIFO queue
    set<GameState*, GameState::Comparator> *visitedStates = new set<GameState*, GameState::Comparator>();
    queue<Move*> *moveQueue = new queue<Move*>();

    // initial values
    moveQueue->push(new Move(state, NULL, 'X'));

    // get final state
    GameState *finalState = GameState::getFinalGameState();

    // stack for final steps (result)
    stack<char> finalSteps;

    // start solving
    do {

        // get next state
        Move *move = moveQueue->front();
        moveQueue->pop();

        // check if we have a visited state
        if(visitedStates->find(move->actualState) != visitedStates->end()) {
            continue;
        }

        // check if it is done
        if(*(move->actualState) == *finalState) {
            while(move->prevMove != NULL) {
                finalSteps.push(move->movement);
                move = move->prevMove;
            }
            break;
        }

        unsigned int **matrix = move->actualState->getAsArray();

        // find '0'
        for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
            for(unsigned int iCol = 0; iCol < GameState::cols; iCol++) {
                if(matrix[iRow][iCol] == 0) {
                    // find the right movement order
                    char *order;
                    if (this->order[0] == 'R') {
                        order = getRandomMoveOrder();
                    } else {
                        order = this->order;
                    }
                    //  process all moves
                    for(int i=0; i<4; i++) {
                        switch (order[i]) {
                            case 'D':
                                moveDown(matrix, iRow, iCol, move, moveQueue);
                                break;
                            case 'G':
                                moveUp(matrix, iRow, iCol, move, moveQueue);
                                break;
                            case 'L':
                                moveLeft(matrix, iRow, iCol, move, moveQueue);
                                break;
                            case 'P':
                                moveRight(matrix, iRow, iCol, move, moveQueue);
                                break;
                        }
                    }
                }
            }
        }

        // clean-up
        for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
            delete[] matrix[iRow];
        }
        delete[] matrix;

    } while(true);

    // form a result
    char *result;
    if (finalSteps.size() > 0) {
        result = new char[finalSteps.size()];
        unsigned int count = 0;
        while(!finalSteps.empty()) {
            result[count++] = finalSteps.top();
            finalSteps.pop();
        }
    } else {
        result = new char[1];
        result[0] = 'X';
    }

    return result;
}
