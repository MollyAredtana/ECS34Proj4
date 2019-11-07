#include "CSVReader.h"
#include <iostream>

CCSVReader::CCSVReader(std::istream &in)
{

}
CCSVReader::~CCSVReader()
{

}
        
bool CCSVReader::End() const
{



}
bool CCSVReader::ReadRow(std::vector< std::string > &row)
{
    if(!End())
    {
        for(auto i : row)
        {
            std::cout << i << std::endl;
        }
    }

}
