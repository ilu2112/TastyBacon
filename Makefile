########################################################################################################################
###                                               M A I N   A P P                                                    ###
########################################################################################################################

SOURCE=src/main
UTILS=$(SOURCE)/utils
STRATEGY=$(SOURCE)/strategy


TastyBacon: $(SOURCE)/main.o $(UTILS)/utils.o $(STRATEGY)/BfsStrategy.o $(UTILS)/GameState.o
	g++ $(STRATEGY)/*.o $(UTILS)/*.o $(SOURCE)/main.o -o TastyBacon
	echo [TastyBacon] -- build successful!
	make -s clean
		
			
$(SOURCE)/main.o: $(SOURCE)/main.cpp
	g++ -c $(SOURCE)/main.cpp -o $(SOURCE)/main.o 
	echo [$(SOURCE)/main.o] -- build successful!
		
		
$(STRATEGY)/BfsStrategy.o: $(STRATEGY)/AbstractStrategy.h $(STRATEGY)/BfsStrategy.h $(STRATEGY)/BfsStrategy.cpp
	g++ -c $(STRATEGY)/BfsStrategy.cpp -o $(STRATEGY)/BfsStrategy.o
	echo [$(STRATEGY)/BfsStrategy.o] -- build successful!
	
	
$(UTILS)/utils.o: $(UTILS)/utils.cpp $(UTILS)/utils.h 
	g++ -c $(UTILS)/utils.cpp -o $(UTILS)/utils.o
	echo [$(UTILS)/utils.o] -- build successful!


$(UTILS)/GameState.o: $(UTILS)/GameState.cpp $(UTILS)/GameState.h
	g++ -c $(UTILS)/GameState.cpp -o $(UTILS)/GameState.o
	echo [$(UTILS)/GameState.o] -- build successful!


$(UTILS)/Move.o: $(UTILS)/Move.cpp
	g++ -c $(UTILS)/Move.cpp -o $(UTILS)/Move.o
	echo [$(UTILS)/Move.o] -- build successful!


clean:
	rm -f $(SOURCE)/*.o
	rm -f $(UTILS)/*.o
	rm -f $(STRATEGY)/*.o
	echo [clean] -- done!



########################################################################################################################
###                                                  T E S T S                                                       ###
########################################################################################################################

TEST=src/test
T_UTILS=$(TEST)/utils
T_STRATEGY=$(TEST)/strategy


test: GameStateTest
	make -s test-clean
	make -s clean
	
	
test-clean:
	rm -f $(T_UTILS)/*.o
	rm -f $(T_UTILS)/*.answer
	rm -f $(T_UTILS)/GameStateTest
	echo [test-clean] -- done!  
	
	
GameStateTest: $(UTILS)/GameState.o $(T_UTILS)/GameStateTest.cpp
	g++ $(T_UTILS)/GameStateTest.cpp $(UTILS)/GameState.o -o $(T_UTILS)/GameStateTest
	./$(T_UTILS)/GameStateTest > $(T_UTILS)/GameStateTest.answer
	diff -q $(T_UTILS)/GameStateTest.answer $(T_UTILS)/GameStateTest.correct
	echo [GameStateTest] -- correct!
