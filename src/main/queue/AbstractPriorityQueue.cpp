#include "AbstractPriorityQueue.h"


AbstractPriorityQueue::AbstractPriorityQueue() {
    this->queue = new set<pair<short, Move *> >();
}


AbstractPriorityQueue::~AbstractPriorityQueue() {
    delete this->queue;
}


Move * AbstractPriorityQueue::next() {
    if (this->queue->empty()) {
        return NULL;
    }
    return this->queue->begin()->second;
}


void AbstractPriorityQueue::push(Move * move) {
    this->queue->insert(make_pair(this->evaluate(move) + move->recursionDepth, move));
}


void AbstractPriorityQueue::pop() {
    if (not this->queue->empty()) {
        this->queue->erase(this->queue->begin());
    }
}


bool AbstractPriorityQueue::isEmpty() {
    return this->queue->empty();
}
