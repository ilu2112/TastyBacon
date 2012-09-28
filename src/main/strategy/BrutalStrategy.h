#ifndef BRUTAL_STRATEGY_H
#define BRUTAL_STRATEGY_H

#include "AbstractStrategy.h"
#include "../queue/AbstractQueue.h"
#include "../utils/Move.cpp"

class BrutalStrategy : public AbstractStrategy {

    private:

        char * order;
        AbstractQueue<Move *> * moveQueue;
        unsigned int maxDepth;


    public:

        BrutalStrategy(char * order,
                       AbstractQueue<Move *> * moveQueue,
                       unsigned int maxDepth = 1000000);

        virtual char * solve(GameState * state,
                             const char * storageFileName);

};


#endif

