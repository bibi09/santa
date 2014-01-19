# Compiler
CC = g++
BINARY = santa


# Compiler options
CCOPT = -W -Wall -std=c++0x

ifndef NDEBUG
    ECHO_DEBUG = "Compile in DEBUG mode"
    CCOPT += -DDEBUG -g
else
    ECHO_DEBUG = "Compile in RELEASE mode"
    CCOPT += -O3
endif

#### PATHS ####
# Path to the root directory of the project
ROOT_DIR = $(realpath ..)
ARCH = $(shell uname -m)

# Executable name and path
BUILD_DIR = $(ROOT_DIR)/build
OBJ_DIR = $(BUILD_DIR)/obj
BINARY_DIR = $(BUILD_DIR)/bin

# Libraries to link
INCLUDES = -I/usr/include/

ALLEGRO_LIBS = -lallegro -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
CV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui
OTHER_LIBS = -lpthread -lm -lopenjpeg
LIBS = $(OTHER_LIBS) $(CV_LIBS) $(ALLEGRO_LIBS)

#### SOURCES ####
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)


ifdef MOUSE
    CCOPT += -DUSE_MOUSE
endif


# Transmit informations to subfolder Makefiles
export CC
export CCOPT
export OBJ_DIR
export INCLUDES
export ROOT_DIR


#### RULES ####
all: infoCompilation MakeOBJ
	@echo Compiling $(BINARY)
	$(CC) $(CCOPT) $(INCLUDES) $(LIBS) $(OBJ_DIR)/*.o -o $(BINARY_DIR)/$(BINARY)
	@mv $(BINARY_DIR)/$(BINARY) $(ROOT_DIR)/

infoCompilation:
	@echo $(ECHO_DEBUG) [architecture = $(ARCH)]

%.o: %.cpp
	@echo "Compiling" $@
	@$(CC) $(CCOPT) -o $(OBJ_DIR)/$@ -c $< $(INCLUDES)

MakeOBJ: $(OBJ)
	@cd image_processing && $(MAKE)
	@cd ../
	@cd screens && $(MAKE)
	@cd ../
	@cd threads && $(MAKE)
	@cd ../
	@cd tools && $(MAKE)
	@cd ../

clean:
	rm -f $(OBJ_DIR)/*.o $(BINARY_DIR)/$(BINARY) 
