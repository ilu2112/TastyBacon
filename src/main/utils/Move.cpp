#ifndef MOVE_CPP
#define MOVE_CPP

#include <stdio.h>

#include "GameState.h"

struct Move {
    
    GameState * actualState;
    unsigned int recursionDepth;
    Move * prevMove;
    char movement;
    
    Move(GameState * actual, Move * prev, char movement) {
        this->actualState = actual;
        this->prevMove = prev;
        this->movement = movement;
        this->recursionDepth = 0;
        if (prev != NULL) {
            this->recursionDepth = prev->recursionDepth + 1;
        }
    }
    
};

#endif
