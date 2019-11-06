CXX=g++

LIBCSV_DIR = libcsv-3.0.3
LIBCSV_LIB = libcsv.a

all : $(LIBCSV_DIR)/.libs/$(LIBCSV_LIB)

$(LIBCSV_DIR)/.libs/$(LIBCSV_LIB): $(LIBCSV_DIR)/Makefile
	cd $(LIBCSV_DIR); make ; cd ..


$(LIBCSV_DIR)/Makefile:
	cd $(LIBCSV_DIR); ./configure ; cd ..

clean:
	cd $(LIBCSV_DIR); make clean; cd ..
	rm -f $(LIBCSV_DIR)/Makefile
