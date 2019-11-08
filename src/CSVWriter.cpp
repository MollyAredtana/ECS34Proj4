#include "CSVWriter.h"
#include <iostream>

CCSVWriter::CCSVWriter(std::ostream &ou) : output(ou)
{
    // output = ou;

}
CCSVWriter::~CCSVWriter()
{
    output.clear();
}

bool CCSVWriter::WriteRow(const std::vector< std::string > &row)
// over here, should we write things out from ou or should we write things into the ou?
{
    if(row.empty())
    {
        return false;
    }

    for(auto i : row)
    {
        for(auto j : i)
        {
            output.put(j);
        }
    }
    return true;
}