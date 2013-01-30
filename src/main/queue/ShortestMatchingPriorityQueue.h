#ifndef SHORTEST_MATCHING_PRIORITY_QUEUE_H
#define SHORTEST_MATCHING_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"


class ShortestMatchingPriorityQueue : public AbstractPriorityQueue {

    public:
    
        ShortestMatchingPriorityQueue();
        
        virtual short evaluate(Move * move);

};


#endif
