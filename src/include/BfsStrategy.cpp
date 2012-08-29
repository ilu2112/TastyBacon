#include "BfsStrategy.h"
#include <string.h>


BfsStrategy::BfsStrategy(char *order) {
    this->order = new char[ strlen(order) ];
    for(unsigned int i = 0; i < strlen(order); i++) {
        this->order[i] = order[i];
    }
}


char *BfsStrategy::solve(GameState *state, const char *storateFileName) {
    char *result = this->order;
    return result;
}
