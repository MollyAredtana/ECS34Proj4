#ifndef CSVREADER_H 	  			 	 
#define CSVREADER_H

#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include "csv.h"
#include <sstream>

class CCSVReader{
    protected:
        std::istream &input;
    
        
        
    public:
        CCSVReader(std::istream &in);
        ~CCSVReader();
        
        bool End() const;
        bool ReadRow(std::vector< std::string > &row);
        //std::istream &input;
};

#endif
