CXX=g++


LIBCSV_DIR = libcsv-3.0.3
# not sure should I do that or not
# LIBCSV_DIR = libcsv-3.0.3 -lexpat
LIBCSV_LIB = libcsv.a

INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TESTBIN_DIR = ./tesbin

CXXFLAGS = --std=c++14 -I $(INCLUDE_DIR) -I $(LIBCSV_DIR)
TESTLDFLAGS = -lgtest -lgtest_main -lpthread
# some problem here need check
CSVOBJS = $(OBJ_DIR)/CSVReader.o $(OBJ_DIR)/CSVWriter.o

CSVTEST = testcsv

all : directories $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) RUNTESTS

RUNTESTS: RUNCSVTEST
	RUNCSVTEST

RUNCSVTEST: $(TESTBIN_DIR)/$(CSVTEST)
	$(TESTBIN_DIR)/$(CSVTEST)

$(LIBCSV_DIR)/.libs/$(LIBCSV_LIB): $(LIBCSV_DIR)/Makefile
	cd $(LIBCSV_DIR); make ; cd ..


$(LIBCSV_DIR)/Makefile:
	cd $(LIBCSV_DIR); ./configure ; cd ..

$(OBJ_DIR)/testcsv.o: $(SRC_DIR)/testcsv.cpp $(INCLUDE_DIR)/CSVReader.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/testcsv.cpp -c -o $(OBJ_DIR)/testcsv.o

$(OBJ_DIR)/CSVReader.o: $(SRC_DIR)/CSVReader.cpp $(INCLUDE_DIR)/CSVReader.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/CSVReader.cpp -c -o $(OBJ_DIR)/CSVReader.o

$(OBJ_DIR)/CSVWriter.o: $(SRC_DIR)/CSVWriter.cpp $(INCLUDE_DIR)/CSVWriter.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/CSVWriter.cpp -c -o $(OBJ_DIR)/CSVWriter.o

$(TESTBIN_DIR)/$(CSVTEST): $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) -o $(TESTBIN_DIR)/$(CSVTEST) $(TESTLDFLAGS)

directories: $(BIN_DIR) $(OBJ_DIR) $(TESTBIN_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TESTBIN_DIR):
	mkdir -p $(TESTBIN_DIR)

clean:
	cd $(LIBCSV_DIR); make clean; cd ..
	rm -f $(LIBCSV_DIR)/Makefile
