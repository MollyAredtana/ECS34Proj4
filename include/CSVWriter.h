#ifndef CSVWRITER_H 	  			 	 
#define CSVWRITER_H

#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <csv.h>
#include <sstream>
#include "StringUtils.h"

class CCSVWriter{
    protected:
        std::ostream &output;

    public:
        CCSVWriter(std::ostream &ou);
        ~CCSVWriter();

        bool WriteRow(const std::vector< std::string > &row);

        long unsigned fields;
        long unsigned rows;
        csv_parser Data;
};

#endif
