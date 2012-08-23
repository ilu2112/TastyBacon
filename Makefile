################################################################################
###                             M A I N   A P P                              ###
################################################################################
SOURCE=src
INCLUDE=$(SOURCE)/include

TastyBacon: $(SOURCE)/main.o $(INCLUDE)/utils.o
	g++ $(INCLUDE)/utils.o $(SOURCE)/main.o -o TastyBacon
	echo [TastyBacon] -- build successful!
	
clean:
	rm -f $(SOURCE)/*.o
	rm -f $(INCLUDE)/*.o
	echo [clean] -- done!
		
$(SOURCE)/main.o: $(SOURCE)/main.cpp
	g++ -c $(SOURCE)/main.cpp -o $(SOURCE)/main.o

$(INCLUDE)/utils.o: $(INCLUDE)/utils.cpp $(INCLUDE)/utils.h
	g++ -c $(INCLUDE)/utils.cpp -o $(INCLUDE)/utils.o
	
$(INCLUDE)/GameState.o: $(INCLUDE)/GameState.cpp $(INCLUDE)/GameState.h
	g++ -c $(INCLUDE)/GameState.cpp -o $(INCLUDE)/GameState.o


################################################################################
###                                T E S T S                                 ###
################################################################################
TEST=$(SOURCE)/test

test: GameStateTest
	make -s test-clean
	
test-clean:
	rm -f $(TEST)/*.answer
	rm -f $(TEST)/*.o
	echo [test-clean] -- done!	
	
GameStateTest: $(INCLUDE)/GameState.o $(TEST)/GameStateTest.cpp
	g++ $(TEST)/GameStateTest.cpp $(INCLUDE)/GameState.o \
		-o $(TEST)/GameStateTest
	./$(TEST)/GameStateTest > $(TEST)/GameStateTest.answer
	diff -q $(TEST)/GameStateTest.answer $(TEST)/GameStateTest.correct
	echo [GameStateTest] -- correct!
	



