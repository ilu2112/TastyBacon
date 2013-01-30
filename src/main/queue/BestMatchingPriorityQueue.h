#ifndef BEST_MATCHING_PRIORITY_QUEUE_H
#define BEST_MATCHING_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"


class BestMatchingPriorityQueue : public AbstractPriorityQueue {

    public:
    
        BestMatchingPriorityQueue();
        
        virtual short evaluate(Move * move);

};


#endif
