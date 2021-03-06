#include "utils/utils.h"
#include "strategy/AbstractStrategy.h"
#include "strategy/BaseStrategy.h"
#include "queue/FifoMoveQueue.h"
#include "queue/LifoMoveQueue.h"
#include "queue/BestMatchingPriorityQueue.h"
#include "queue/ShortestMatchingPriorityQueue.h"
#include "queue/MyPriorityQueue.h"
#include "utils/Move.cpp"
#include "utils/GameState.h"
#include <string.h>
#include <stdio.h>
#include <set>
#include <unistd.h>
#include <sys/resource.h>
#include <time.h>

#define _FILE_OFFSET_BITS 64

// parameters
const char * BFS_SHORT = "-b";
const char * BFS_LONG = "--bfs";
const char * DFS_SHORT = "-d";
const char * DFS_LONG = "--dfs";
const char * AS_SHORT = "-a";
const char * AS_LONG = "--a";

using namespace std;

int main(int argc, char **argv) {
    // limits
    // Memory (2GB)
    rlimit64 memlock;
    getrlimit64(RLIMIT_AS, &memlock);
    memlock.rlim_cur = 0x40000000LL * 2;
    memlock.rlim_max = 0x40000000LL * 2;
    setrlimit64(RLIMIT_AS, &memlock);
    // time (30 minutes)
    rlimit64 timelock;
    getrlimit64(RLIMIT_CPU, &timelock);
    timelock.rlim_cur = 0x708;
    timelock.rlim_max = 0x708;
    setrlimit64(RLIMIT_CPU, &timelock);
    
    // get input
    unsigned int rows;
    unsigned int cols;
    unsigned int **matrix;
    getInput(rows, cols, matrix);

    GameState::setSize(rows, cols);
    GameState *gs = new GameState(matrix);

    char * order;
    AbstractStrategy * strategy;
    
    // parse parameters
    if ( strcmp(argv[1], BFS_SHORT) == 0 || strcmp(argv[1], BFS_LONG) == 0) {
        // BFS
        order = argv[2];
        strategy = new BaseStrategy(order, new FifoMoveQueue());
    } else if ( strcmp(argv[1], DFS_SHORT) == 0 || strcmp(argv[1], DFS_LONG) == 0 ) {
        // DFS
        order = argv[2];
        strategy = new BaseStrategy(order, new LifoMoveQueue());
    } else if ( strcmp(argv[1], AS_SHORT) == 0 || strcmp(argv[1], AS_LONG) == 0 ) {
        // A*
        order = argv[3];
        if (argv[2][0] == '1') {
            // 1st heuristic
             strategy = new BaseStrategy(order, new BestMatchingPriorityQueue());
        } else if (argv[2][0] == '2') {
            // 2nd heuristic
            strategy = new BaseStrategy(order, new ShortestMatchingPriorityQueue());
        } else {
            // 3rd heuristic
            strategy = new BaseStrategy(order, new MyPriorityQueue());
        }
    }
    
    strategy->statisticsEnabled = true;
    char * answer = strategy->solve(gs);
    
    if (answer[0] == 'X') {
        printf("-1\n");
    } else {
        int size = strlen(answer);
        printf("%d\n", size);
        // printf("%s\n", answer);
    }
    
    return 0;
}
