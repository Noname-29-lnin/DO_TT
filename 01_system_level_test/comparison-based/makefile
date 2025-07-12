MAIN_TEST := main

all: clean complite run

complite:
	g++ $(MAIN_TEST).cpp -o $(MAIN_TEST)

run:
	./$(MAIN_TEST) | tee complite.log

clean:
	rm -rf $(MAIN_TEST)
