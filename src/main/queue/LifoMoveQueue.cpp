#include "LifoMoveQueue.h"


LifoMoveQueue::LifoMoveQueue() {
    this->lifoQueue = new std::stack<Move *>();
}


Move * LifoMoveQueue::next() {
    return this->lifoQueue->top();
}


void LifoMoveQueue::push(Move * move) {
    this->lifoQueue->push(move);
}


void LifoMoveQueue::pop() {
    this->lifoQueue->pop();
}


bool LifoMoveQueue::isEmpty() {
    return this->lifoQueue->empty();
}
