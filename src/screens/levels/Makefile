SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	@cd hud && $(MAKE)
	@cd ../
	@cd items && $(MAKE)
	@cd ../
	@cd rules_screens && $(MAKE)
	@cd ../

%.o: %.cpp
	@echo "Compiling" $@
	@$(CC) $(CCOPT) -o $(OBJ_DIR)/$@ -c $< $(INCLUDES) 
