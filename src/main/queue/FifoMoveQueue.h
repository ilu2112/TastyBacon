#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

#include <queue>

#include "AbstractMoveQueue.h"

class FifoMoveQueue : public AbstractMoveQueue {

    private:

        std::queue<Move *> * fifoQueue;


    public:

        FifoMoveQueue();

        ~FifoMoveQueue();

        virtual Move * next();

        virtual void push(Move * move);

        virtual void pop();

        virtual bool isEmpty();


};


#endif
