#ifndef CSVWRITER_H 	  			 	 
#define CSVWRITER_H

#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "csv.h"
#include <sstream>

class CCSVWriter{
    protected:

    public:
        CCSVWriter(std::ostream &ou);
        ~CCSVWriter();

        bool WriteRow(const std::vector< std::string > &row);
};

#endif
