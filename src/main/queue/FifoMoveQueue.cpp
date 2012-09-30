#include "FifoMoveQueue.h"


FifoMoveQueue::FifoMoveQueue() {
    this->fifoQueue = new std::queue<Move *>();
}


FifoMoveQueue::~FifoMoveQueue() {
    delete this->fifoQueue;
}


Move * FifoMoveQueue::next() {
    return this->fifoQueue->front();
}


void FifoMoveQueue::push(Move * move) {
    this->fifoQueue->push(move);
}


void FifoMoveQueue::pop() {
    this->fifoQueue->pop();
}


bool FifoMoveQueue::isEmpty() {
    return this->fifoQueue->empty();
}
