########################################################################################################################
###                                               M A I N   A P P                                                    ###
########################################################################################################################

SOURCE=src
INCLUDE=$(SOURCE)/include

TastyBacon: $(SOURCE)/main.o $(INCLUDE)/utils.o $(INCLUDE)/BfsStrategy.o $(INCLUDE)/GameState.o
	g++ $(INCLUDE)/*.o $(SOURCE)/main.o -o TastyBacon
	echo [TastyBacon] -- build successful!


$(SOURCE)/main.o: $(SOURCE)/main.cpp
	g++ -c $(SOURCE)/main.cpp -o $(SOURCE)/main.o


$(INCLUDE)/BfsStrategy.o: $(INCLUDE)/AbstractStrategy.h $(INCLUDE)/BfsStrategy.h $(INCLUDE)/BfsStrategy.cpp \
	$(INCLUDE)/utils.o $(INCLUDE)/Move.o
	g++ -c $(INCLUDE)/utils.o $(INCLUDE)/Move.o $(INCLUDE)/BfsStrategy.cpp -o $(INCLUDE)/BfsStrategy.o


$(INCLUDE)/utils.o: $(INCLUDE)/utils.cpp $(INCLUDE)/utils.h $(INCLUDE)/GameState.o $(INCLUDE)/Move.o
	g++ -c $(INCLUDE)/GameState.o $(INCLUDE)/Move.o $(INCLUDE)/utils.cpp -o $(INCLUDE)/utils.o


$(INCLUDE)/GameState.o: $(INCLUDE)/GameState.cpp $(INCLUDE)/GameState.h
	g++ -c $(INCLUDE)/GameState.cpp -o $(INCLUDE)/GameState.o


$(INCLUDE)/Move.o: $(INCLUDE)/Move.cpp
	g++ -c $(INCLUDE)/Move.cpp -o $(INCLUDE)/Move.o


clean:
	rm -f $(SOURCE)/*.o
	rm -f $(INCLUDE)/*.o
	echo [clean] -- done!



########################################################################################################################
###                                                  T E S T S                                                       ###
########################################################################################################################

TEST=$(SOURCE)/test


test: GameStateTest
	make -s test-clean


test-clean:
	rm -f $(TEST)/*.answer
	rm -f $(TEST)/*.o
	rm -f $(INCLUDE)/GameState.o
	rm -f $(TEST)/GameStateTest
	echo [test-clean] -- done!


GameStateTest: $(INCLUDE)/GameState.o $(TEST)/GameStateTest.cpp
	g++ $(TEST)/GameStateTest.cpp $(INCLUDE)/GameState.o -o $(TEST)/GameStateTest
	./$(TEST)/GameStateTest > $(TEST)/GameStateTest.answer
	diff -q $(TEST)/GameStateTest.answer $(TEST)/GameStateTest.correct
	echo [GameStateTest] -- correct!
