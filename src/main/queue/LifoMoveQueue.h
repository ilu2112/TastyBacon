#ifndef LIFO_QUEUE_H
#define LIFO_QUEUE_H

#include <stack>

#include "AbstractMoveQueue.h"

class LifoMoveQueue : public AbstractMoveQueue {

    private:

        std::stack<Move *> * lifoQueue;


    public:

        LifoMoveQueue();

        virtual Move * next();

        virtual void push(Move * move);

        virtual void pop();

        virtual bool isEmpty();


};


#endif
