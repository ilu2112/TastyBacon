#include <stdio.h>
#include "../include/GameState.h"
#include "../include/utils.h"

int main() {

    // make an array of values
    unsigned int rows = 3;
    unsigned int cols = 3;
    GameState::setSize(rows, cols);
    unsigned int counter = 0;
    unsigned int **array = new unsigned int*[rows];
    for(unsigned int i=0; i<rows; i++) {
        array[i] = new unsigned int[cols];
        for(unsigned j=0; j<cols; j++) {
            array[i][j] = counter++;
        }
    }
    
    // get state's value
    long long int stateVal = GameState::getAsInt(array);
    
    // test GameState::getAsInt
    printf("%lld\n", stateVal);
        
    // test GameState::getAsArray
    GameState::setSize(rows, cols);
    GameState *gs = new GameState(stateVal);
    unsigned int **arr  = gs->getAsArray();
    for(unsigned int i=0; i<rows; i++) {
        for(unsigned int j=0; j<cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
