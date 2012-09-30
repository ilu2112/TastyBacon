########################################################################################################################
###                                               M A I N   A P P                                                    ###
########################################################################################################################

SOURCE=src/main
UTILS=$(SOURCE)/utils
STRATEGY=$(SOURCE)/strategy
QUEUE=$(SOURCE)/queue


TastyBacon: $(SOURCE)/main.o $(UTILS)/utils.o $(STRATEGY)/BaseStrategy.o $(UTILS)/GameState.o \
		    $(QUEUE)/FifoMoveQueue.o $(QUEUE)/LifoMoveQueue.o
	g++ $(STRATEGY)/*.o $(UTILS)/*.o $(SOURCE)/main.o $(QUEUE)/*.o -o TastyBacon
	echo [TastyBacon] -- build successful!
	make -s clean


$(SOURCE)/main.o:
	g++ -c $(SOURCE)/main.cpp -o $(SOURCE)/main.o
	echo [$(SOURCE)/main.o] -- build successful!


$(STRATEGY)/BaseStrategy.o:
	g++ -c $(STRATEGY)/BaseStrategy.cpp -o $(STRATEGY)/BaseStrategy.o
	echo [$(STRATEGY)/BaseStrategy.o] -- build successful!


$(UTILS)/utils.o:
	g++ -c $(UTILS)/utils.cpp -o $(UTILS)/utils.o
	echo [$(UTILS)/utils.o] -- build successful!


$(UTILS)/GameState.o:
	g++ -c $(UTILS)/GameState.cpp -o $(UTILS)/GameState.o
	echo [$(UTILS)/GameState.o] -- build successful!


$(UTILS)/Move.o:
	g++ -c $(UTILS)/Move.cpp -o $(UTILS)/Move.o
	echo [$(UTILS)/Move.o] -- build successful!


${QUEUE}/FifoMoveQueue.o:
	g++ -c $(QUEUE)/FifoMoveQueue.cpp -o $(QUEUE)/FifoMoveQueue.o
	echo [${QUEUE}/FifoMoveQueue.o] -- build successful!


${QUEUE}/LifoMoveQueue.o:
	g++ -c $(QUEUE)/LifoMoveQueue.cpp -o $(QUEUE)/LifoMoveQueue.o
	echo [${QUEUE}/LifoMoveQueue.o] -- build successful!


clean:
	rm -f $(SOURCE)/*.o
	rm -f $(UTILS)/*.o
	rm -f $(STRATEGY)/*.o
	rm -f $(QUEUE)/*.o
	echo [clean] -- done!



########################################################################################################################
###                                                  T E S T S                                                       ###
########################################################################################################################

TEST=src/test
T_UTILS=$(TEST)/utils
T_STRATEGY=$(TEST)/strategy


COMPARE =	( \
				diff -q $2 $3 >/dev/null \
				&& echo '[$1] --\033[32m correct! \033[0m' \
			) || ( \
				echo '[$1] --\033[31m wrong! \033[0m' \
				&& exit 0 \
			)

test:
	make -s GameStateTest
	make -s test-clean
	make -s clean


test-clean:
	rm  -f $(T_UTILS)/*.answer
	rm  -f $(T_UTILS)/*.o
	rm  -f $(T_UTILS)/GameStateTest
	echo [test-clean] -- done!


GameStateTest: $(UTILS)/GameState.o
	g++ $(T_UTILS)/GameStateTest.cpp $(UTILS)/GameState.o -o $(T_UTILS)/GameStateTest
	./$(T_UTILS)/GameStateTest > $(T_UTILS)/GameStateTest.answer
	$(call COMPARE,GameStateTest, $(T_UTILS)/GameStateTest.answer, $(T_UTILS)/GameStateTest.correct)
