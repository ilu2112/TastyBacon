#include <stdio.h>

#include "../../main/queue/FifoQueue.h"


int main() {

    FifoQueue<int> * myQueue = new FifoQueue<int>();
    myQueue->push(1);
    myQueue->push(2);
    myQueue->push(3);
    printf("%d\n", myQueue->next());
    myQueue->push(4);
    while(!myQueue->isEmpty()) {
        printf("%d\n", myQueue->next());
        myQueue->pop();
    }
    delete myQueue;

    return 0;
}
