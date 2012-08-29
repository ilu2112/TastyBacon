//  BFS Strategy with FIFO queue.

#include "BfsStrategy.h"
#include "GameState.h"
#include "utils.h"
#include "Move.cpp"
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string.h>

#include <stdio.h>

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
   
    // start solving
    do {
        
        // get next state
        Move *move = moveQueue->front();
        moveQueue->pop();       
        
        // check if we have a visited state
        if(visitedStates->find(move->actualState) != visitedStates->end()) {
            printf("visited!\n");
            break;
        }
        
        // check if it is done
        if(*(move->actualState) == *finalState) {
            printf("done!\n");
            while(move->prevMove != NULL) {
                printf("%c", move->movement);
                move = move->prevMove;
            }
            printf("\n");
            break;
        }
        
        unsigned int **matrix = move->actualState->getAsArray();
        
        // find '0'
        for(unsigned int iRow = 0; iRow < GameState::rows; iRow++) {
            for(unsigned int iCol = 0; iCol < GameState::cols; iCol++) {
                if(matrix[iRow][iCol] == 0) {
                    // process all moves
                    moveDown(matrix, iRow, iCol, move, moveQueue);
                    moveUp(matrix, iRow, iCol, move, moveQueue);
                    moveLeft(matrix, iRow, iCol, move, moveQueue);
                    moveRight(matrix, iRow, iCol, move, moveQueue);
                }
            }
        }
        
    } while(true);
    
    // form result
    char *result = new char[10];
    return result;
}
