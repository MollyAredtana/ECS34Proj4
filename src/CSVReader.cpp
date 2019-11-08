#include "CSVReader.h"
#include <iostream>
#include <string>

CCSVReader::CCSVReader(std::istream &in) : input(in)
{
    // input = in;
}
CCSVReader::~ CCSVReader()
{
    input.clear();
    
}
        
bool CCSVReader::End() const  // not sure about this one
{
    int length = 0;
    input.seekg(0, input.end);
    if(input.tellg() == 0)
    {
        return true;
    }

    return !input.eof();

}
bool CCSVReader::ReadRow(std::vector< std::string > &row) // who is going to give the input?
{
    // if it doesn't requires print it out, I can just use seekg to go through everything 
    // here, and ask professor about one row each column thing
    int pos = 0;
    int length = 0;
    std::string output;


    input.seekg(0, input.end);
    if(input.tellg() == 0)
    {
        return false;
    }
    input.seekg(0, input.beg);
    char c;
    std::string string;
    while(input.get(c))
    {
        string += c;
    }
    std::string newstring;
    for(auto i : string)
    {
        if(i != ' ' && i != ',' && i != 0xD && i != 0xA)
        {
            newstring += i;
            row.resize(newstring.length());
            row[pos] = i;
            pos++;
        }
    }

    return true;
}
