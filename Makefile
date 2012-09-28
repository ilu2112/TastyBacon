########################################################################################################################
###                                               M A I N   A P P                                                    ###
########################################################################################################################

SOURCE=src/main
UTILS=$(SOURCE)/utils
STRATEGY=$(SOURCE)/strategy
QUEUE=$(SOURCE)/queue


TastyBacon: $(SOURCE)/main.o $(UTILS)/utils.o $(STRATEGY)/BrutalStrategy.o $(UTILS)/GameState.o
	g++ $(STRATEGY)/*.o $(UTILS)/*.o $(SOURCE)/main.o -o TastyBacon
	echo [TastyBacon] -- build successful!
	make -s clean


$(SOURCE)/main.o:
	g++ -c $(SOURCE)/main.cpp -o $(SOURCE)/main.o
	echo [$(SOURCE)/main.o] -- build successful!


$(STRATEGY)/BrutalStrategy.o:
	g++ -c $(STRATEGY)/BrutalStrategy.cpp -o $(STRATEGY)/BrutalStrategy.o
	echo [$(STRATEGY)/BrutalStrategy.o] -- build successful!


$(UTILS)/utils.o:
	g++ -c $(UTILS)/utils.cpp -o $(UTILS)/utils.o
	echo [$(UTILS)/utils.o] -- build successful!


$(UTILS)/GameState.o:
	g++ -c $(UTILS)/GameState.cpp -o $(UTILS)/GameState.o
	echo [$(UTILS)/GameState.o] -- build successful!


$(UTILS)/Move.o:
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
T_QUEUE=$(TEST)/queue


COMPARE =	( \
				diff -q $2 $3 >/dev/null \
				&& echo '[$1] --\033[32m correct! \033[0m' \
			) || ( \
				echo '[$1] --\033[31m wrong! \033[0m' \
				&& exit 0 \
			)

test:
	make -s GameStateTest
	make -s FifoQueueTest
	make -s LifoQueueTest
	make -s test-clean
	make -s clean


test-clean:
	rm  -f $(T_UTILS)/*.answer
	rm  -f $(T_UTILS)/*.o
	rm  -f $(T_UTILS)/GameStateTest
	rm  -f $(T_QUEUE)/*.answer
	rm  -f $(T_QUEUE)/*.o
	rm  -f $(T_QUEUE)/FifoQueueTest
	rm  -f $(T_QUEUE)/LifoQueueTest
	echo [test-clean] -- done!


GameStateTest: $(UTILS)/GameState.o
	g++ $(T_UTILS)/GameStateTest.cpp $(UTILS)/GameState.o -o $(T_UTILS)/GameStateTest
	./$(T_UTILS)/GameStateTest > $(T_UTILS)/GameStateTest.answer
	$(call COMPARE,GameStateTest, $(T_UTILS)/GameStateTest.answer, $(T_UTILS)/GameStateTest.correct)


FifoQueueTest:
	g++ $(T_QUEUE)/FifoQueueTest.cpp -o $(T_QUEUE)/FifoQueueTest
	./$(T_QUEUE)/FifoQueueTest > $(T_QUEUE)/FifoQueueTest.answer
	$(call COMPARE,FifoQueueTest, $(T_QUEUE)/FifoQueueTest.answer, $(T_QUEUE)/FifoQueueTest.correct)


LifoQueueTest:
	g++ $(T_QUEUE)/LifoQueueTest.cpp -o $(T_QUEUE)/LifoQueueTest
	./$(T_QUEUE)/LifoQueueTest > $(T_QUEUE)/LifoQueueTest.answer
	$(call COMPARE,LifoQueueTest, $(T_QUEUE)/LifoQueueTest.answer, $(T_QUEUE)/LifoQueueTest.correct)
