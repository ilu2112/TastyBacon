#ifndef ABSTRACT_STRATEGY_H
#define ABSTRACT_STRATEGY_H

#include "GameState.h"
#include <stdio.h>


class AbstractStrategy {
	
	public:
	
		virtual char *solve(GameState *state, 
							const char *storateFileName) = 0;
							  
};


#endif
