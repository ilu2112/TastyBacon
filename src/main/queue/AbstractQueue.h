#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H

template <typename T>
class AbstractQueue {

    public:

        virtual T next() = 0;
        virtual void pop() = 0;
        virtual bool isEmpty() = 0;
        virtual void push(T element) = 0;


};


#endif
