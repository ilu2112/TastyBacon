#include <stdio.h>

#include "../../main/queue/LifoQueue.h"


int main() {

    LifoQueue<int> * myQueue = new LifoQueue<int>();
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
