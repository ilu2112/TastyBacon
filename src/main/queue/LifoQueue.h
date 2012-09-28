#ifndef LIFO_QUEUE_H
#define LIFO_QUEUE_H

#include <stack>

#include "AbstractQueue.h"

template <class T>
class LifoQueue : public AbstractQueue<T> {

    private:

        std::stack<T> * lifoQueue;


    public:

        LifoQueue() {
            this->lifoQueue = new std::stack<T>();
        }


        virtual T next() {
            return this->lifoQueue->top();
        }


        virtual void push(T element) {
            this->lifoQueue->push(element);
        }


        virtual void pop() {
            this->lifoQueue->pop();
        }


        virtual bool isEmpty() {
            return this->lifoQueue->empty();
        }


};


#endif
