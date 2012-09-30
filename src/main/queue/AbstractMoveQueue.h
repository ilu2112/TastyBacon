#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H

#include "../utils/Move.cpp"

class AbstractMoveQueue {

    public:

        virtual Move * next() = 0;
        virtual void pop() = 0;
        virtual bool isEmpty() = 0;
        virtual void push(Move * move) = 0;


};


#endif
