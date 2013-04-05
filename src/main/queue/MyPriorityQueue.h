#ifndef MY_PRIORITY_QUEUE_H
#define MY_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"


class MyPriorityQueue : public AbstractPriorityQueue {

    public:
    
        MyPriorityQueue();
        
        virtual short evaluate(Move * move);

};


#endif
