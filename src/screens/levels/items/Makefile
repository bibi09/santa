SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	@cd bonus && $(MAKE)
	@cd ../
	@cd confetti && $(MAKE)
	@cd ../
	@cd malus && $(MAKE)
	@cd ../

%.o: %.cpp
	@echo "Compiling" $@
	@$(CC) $(CCOPT) -o $(OBJ_DIR)/$@ -c $< $(INCLUDES) 
