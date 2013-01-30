#ifndef ABSTRACT_PRIORITY_QUEUE_H
#define ABSTRACT_PRIORITY_QUEUE_H

#include <set>
#include "AbstractMoveQueue.h"
using namespace std;


class AbstractPriorityQueue : public AbstractMoveQueue {


    private:

        set<pair<short, Move *> > * queue;



    public:
        
        AbstractPriorityQueue();

        ~AbstractPriorityQueue();
        
        virtual Move * next();

        virtual void push(Move * move);

        virtual void pop();

        virtual bool isEmpty();
        
        virtual short evaluate(Move * move) = 0;


};


#endif
