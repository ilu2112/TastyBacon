#include <set>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "utils/GameState.h"
#include "utils/Move.cpp"
#include "utils/utils.cpp"

using namespace std;


// create a set of visited states
set<GameState *, GameState::Comparator> * visitedStates = new set<GameState *, GameState::Comparator>();

string STATES_DIR = "/home/marcin/Documents/fiveteen/";

const char * ORDER = "DLGP";

int GEN_QUANTITY[21];

int main() {
    // initial state
    unsigned int ** matrix = new unsigned int*[4];
    unsigned int counter = 1;
    for (int i=0; i<4; i++) {
        matrix[i] = new unsigned int[4];
        for (int j=0; j<4; j++) {
            matrix[i][j] = counter;
            counter = (counter + 1) % 16;
        }
    }
    GameState::setSize(4, 4);
    GameState *gs = new GameState(GameState::getAsInt(matrix));
    visitedStates->insert(gs);
    Move * mv = new Move(gs, NULL, 'X');
    queue<Move *> que;
    que.push(mv);
    
    while(GEN_QUANTITY[20] < 10) {
        // next move
        Move * next = que.front();
        que.pop();
        // retrieve matrix
        unsigned int ** mat = next->actualState->getAsArray();
        if ((next->recursionDepth < 7) || GEN_QUANTITY[next->recursionDepth] < 10) {
            // save move to the file
            // create directory?
            if (GEN_QUANTITY[next->recursionDepth] == 0) {
                ostringstream oss;
                oss << "mkdir ";
                oss << STATES_DIR;
                oss << next->recursionDepth;
                system(oss.str().c_str());
            }
            // create file
            ostringstream oss;
            oss << STATES_DIR << next->recursionDepth << "/" << GEN_QUANTITY[next->recursionDepth];
            FILE * pFile;
            pFile = fopen (oss.str().c_str(), "w");
            if (pFile) {
                fprintf(pFile, "4 4\n");
                for (int i=0; i<4; i++) {
                    for (int j=0; j<4; j++) {
                        fprintf(pFile, "%d", mat[i][j]);
                        if (j != 3) {
                            fprintf(pFile, " ");
                        }
                    }
                    fprintf(pFile, "\n");
                }
            }
            fclose (pFile);
            // increment quantity
            GEN_QUANTITY[next->recursionDepth]++;
        }
            // create new moves
            for(unsigned int iRow = 0; iRow < 4; iRow++) {
                for(unsigned int iCol = 0; iCol < 4; iCol++) {
                    if(mat[iRow][iCol] == 0) {
                        //  process all moves
                        for (int i=0; i<4; i++) {
                            Move * nextMove = doMove(mat, iRow, iCol, ORDER[i], next);
                            if (nextMove != NULL && visitedStates->find(nextMove->actualState) == visitedStates->end()) {
                                que.push(nextMove);
                                visitedStates->insert(nextMove->actualState);
                            }
                        }
                    }
                }
            }
       
    }
    return 0;
}
