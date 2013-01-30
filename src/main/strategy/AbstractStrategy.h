#ifndef ABSTRACT_STRATEGY_H
#define ABSTRACT_STRATEGY_H

#include "../utils/GameState.h"


class AbstractStrategy {

    public:

        virtual char * solve(GameState * state) = 0;

};


#endif
