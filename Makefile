CXX=g++


LIBCSV_DIR = libcsv-3.0.3
# not sure should I do that or not
# LIBCSV_DIR = libcsv-3.0.3 -lexpat
LIBCSV_LIB = libcsv.a

INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TESTBIN_DIR = ./testbin

CXXFLAGS = --std=c++14 -I $(INCLUDE_DIR) -I $(LIBCSV_DIR)
TESTLDFLAGS = -lgtest -lgtest_main -lpthread
EXlib = -lexpat


# 把下面make rule 啥的全做一遍



#try to declare the library here
# some problem here need check
CSVOBJS = $(OBJ_DIR)/CSVReader.o $(OBJ_DIR)/CSVWriter.o  $(OBJ_DIR)/StringUtils.o
XMLOBJS = $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o  $(OBJ_DIR)/StringUtils.o
TotalOBJS = $(OBJ_DIR)/CSVReader.o $(OBJ_DIR)/CSVWriter.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o  $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/Path.o
MAIN_OBJ = $(OBJ_DIR)/main.o

PROG_NAME = BabyName

CSVTEST = testcsv
XMLTEST = testxml

all : directories $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) RUNTESTS $(BIN_DIR)/$(PROG_NAME)

RUNTESTS: RUNCSVTEST

RUNCSVTEST: $(TESTBIN_DIR)/$(CSVTEST) $(TESTBIN_DIR)/$(XMLTEST)
	$(TESTBIN_DIR)/$(CSVTEST)
	$(TESTBIN_DIR)/$(XMLTEST)

$(LIBCSV_DIR)/.libs/$(LIBCSV_LIB): $(LIBCSV_DIR)/Makefile
	cd $(LIBCSV_DIR); make ; cd ..


$(LIBCSV_DIR)/Makefile:
	cd $(LIBCSV_DIR); ./configure ; cd ..

$(BIN_DIR)/$(PROG_NAME): $(TotalOBJS) $(MAIN_OBJ) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB)
	$(CXX) $(MAIN_OBJ) $(TotalOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) $(EXlib) -o $(BIN_DIR)/$(PROG_NAME) $(CXXFLAGS) $(TESTLDFLAGS)

$(TESTBIN_DIR)/$(CSVTEST): $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) -o $(TESTBIN_DIR)/$(CSVTEST) $(TESTLDFLAGS)

$(OBJ_DIR)/testcsv.o: $(SRC_DIR)/testcsv.cpp $(INCLUDE_DIR)/CSVReader.h $(INCLUDE_DIR)/CSVWriter.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/testcsv.cpp -c -o $(OBJ_DIR)/testcsv.o

$(OBJ_DIR)/CSVReader.o: $(SRC_DIR)/CSVReader.cpp $(INCLUDE_DIR)/CSVReader.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/CSVReader.cpp -c -o $(OBJ_DIR)/CSVReader.o

$(OBJ_DIR)/CSVWriter.o: $(SRC_DIR)/CSVWriter.cpp $(INCLUDE_DIR)/CSVWriter.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/CSVWriter.cpp -c -o $(OBJ_DIR)/CSVWriter.o
#try to link the library here
# $(TESTBIN_DIR)/$(CSVTEST): $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB)
# 	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/testcsv.o $(CSVOBJS) $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB) -o $(TESTBIN_DIR)/$(CSVTEST) $(TESTLDFLAGS)

$(TESTBIN_DIR)/$(XMLTEST): $(OBJ_DIR)/testxml.o $(XMLOBJS)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/testxml.o $(XMLOBJS) -o $(TESTBIN_DIR)/$(XMLTEST) $(TESTLDFLAGS) $(EXlib)

$(OBJ_DIR)/testxml.o: $(SRC_DIR)/testxml.cpp $(INCLUDE_DIR)/XMLReader.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/testxml.cpp -c -o $(OBJ_DIR)/testxml.o

$(OBJ_DIR)/XMLReader.o: $(SRC_DIR)/XMLReader.cpp $(INCLUDE_DIR)/XMLReader.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/XMLReader.cpp -c -o $(OBJ_DIR)/XMLReader.o

$(OBJ_DIR)/XMLWriter.o: $(SRC_DIR)/XMLWriter.cpp $(INCLUDE_DIR)/XMLWriter.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/XMLWriter.cpp -c -o $(OBJ_DIR)/XMLWriter.o

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INCLUDE_DIR)/StringUtils.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/StringUtils.cpp -c -o $(OBJ_DIR)/StringUtils.o

$(OBJ_DIR)/Path.o: $(SRC_DIR)/Path.cpp $(INCLUDE_DIR)/Path.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/Path.cpp -c -o $(OBJ_DIR)/Path.o
# #try to link the library here
# $(TESTBIN_DIR)/$(XMLTEST): $(OBJ_DIR)/testxml.o $(XMLOBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/testxml.o $(XMLOBJS) -o $(TESTBIN_DIR)/$(XMLTEST) $(TESTLDFLAGS) $(EXlib)

$(MAIN_OBJ): $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/CSVReader.h $(INCLUDE_DIR)/CSVWriter.h $(INCLUDE_DIR)/XMLReader.h $(INCLUDE_DIR)/XMLWriter.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp -c -o $(OBJ_DIR)/main.o

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
