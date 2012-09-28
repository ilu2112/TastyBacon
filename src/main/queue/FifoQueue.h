#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

#include <queue>

#include "AbstractQueue.h"

template <class T>
class FifoQueue : public AbstractQueue<T> {

    private:

        std::queue<T> * fifoQueue;


    public:

        FifoQueue() {
            this->fifoQueue = new std::queue<T>();
        }


        ~FifoQueue() {
            delete this->fifoQueue;
        }


        virtual T next() {
            return this->fifoQueue->front();
        }


        virtual void push(T element) {
            this->fifoQueue->push(element);
        }


        virtual void pop() {
            this->fifoQueue->pop();
        }


        virtual bool isEmpty() {
            return this->fifoQueue->empty();
        }


};


#endif
