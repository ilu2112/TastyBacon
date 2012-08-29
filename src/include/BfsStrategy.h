#ifndef BFS_STRATEGY_H
#define BFS_STRATEGY_H

#include "AbstractStrategy.h"


class BfsStrategy : public AbstractStrategy {

	private:
	
		char *order;
		

	public:
		
		BfsStrategy(char *order);
		virtual char *solve(GameState *state, 
							const char *storateFileName);

};


#endif
