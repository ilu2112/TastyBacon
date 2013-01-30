#ifndef ABSTRACT_PRIORITY_QUEUE_H
#define ABSTRACT_PRIORITY_QUEUE_H

#include <queue>

#include "AbstractMoveQueue.h"

class AbstractPriorityQueue : public AbstractMoveQueue {


    private:

        virtual short evaluate(Move * move) = 0;


    public:

        virtual Move * next();

        virtual void push(Move * move);

        virtual void pop();

        virtual bool isEmpty();


};


#endif
