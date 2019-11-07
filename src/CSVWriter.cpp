#include "CSVWriter.h"
#include <iostream>

CCSVWriter::CCSVWriter(std::ostream &ou)
{

}
CCSVWriter::~CCSVWriter()
{

}

bool CCSVWriter::WriteRow(const std::vector< std::string > &row)
{
    if(row.empty())
    {
        return false;
    }

    for(auto i : row)
    {
        for(auto j : i)
        {
            std::cout << j << std::endl;
        }
    }
    return true;
}