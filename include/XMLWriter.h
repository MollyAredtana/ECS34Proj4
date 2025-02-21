#ifndef XMLWRITER_H 	  			 	 
#define XMLWRITER_H

#include "XMLEntity.h"
#include <stack>
#include <istream>

class CXMLWriter{
    private:
    	std::ostream &DOutput;
    	std::stack <std::string> Elements;
    	
        
    public:
        CXMLWriter(std::ostream &os);
        ~CXMLWriter();
        
        bool Flush();
        bool WriteEntity(const SXMLEntity &entity);
};

#endif                         