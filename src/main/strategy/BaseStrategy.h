#ifndef BASE_STRATEGY_H
#define BASE_STRATEGY_H

#include "AbstractStrategy.h"
#include "../queue/AbstractMoveQueue.h"
#include "../utils/Move.cpp"

class BaseStrategy : public AbstractStrategy {

    private:

        char * order;
        AbstractMoveQueue * moveQueue;
        unsigned int maxDepth;


    public:

        BaseStrategy(char * order,
                     AbstractMoveQueue * moveQueue,
                     unsigned int maxDepth = 1000000);

        virtual char * solve(GameState * state);

};


#endif

