#ifndef MOVE_CPP
#define MOVE_CPP

#include "GameState.h"

struct Move {
    
    GameState *actualState;
    Move *prevMove;
    char movement;
    
    Move(GameState *actual, Move *prev, char movement) {
        this->actualState = actual;
        this->prevMove = prev;
        this->movement = movement;
    }
    
};

#endif
