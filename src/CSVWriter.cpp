#include "CSVWriter.h"
#include <iostream>


// void cb1 (void *s, size_t len, void *data)
// {
//     std::cout << __LINE__ << " @  line   " << std::endl;
//     ((struct CCSVWriter *)data)->fields++;
//     // int row = ((struct CCSVReader *)data)->CurRow;
//     // auto str = (char *)s;
//     // printf("%.*s\n", len, str);
// }

// void cb2 (int c, void *data)
// {
//     std::cout << __LINE__ << " @  line   " << std::endl;
//     ((struct CCSVWriter *)data)->rows++;
// }

void static cb1 (void *s, size_t len, void *data) { ((struct CCSVWriter *)data)->fields++; }
void static cb2 (int c, void *data) { ((struct CCSVWriter *)data)->rows++; }


CCSVWriter::CCSVWriter(std::ostream &ou) : output(ou)
{
    csv_init(& Data, 0);
    // output = ou;

}
CCSVWriter::~CCSVWriter()
{
    // output.clear();
    void *c;

    // input.clear();
    // csv_fini( & Data, cb1, cb2, c);
    csv_free(& Data);
}

bool CCSVWriter::WriteRow(const std::vector< std::string > &row)
// over here, should we write things out from ou or should we write things into the ou?
{
    // std::string GoodForm;
    // row may contains "1",  2, 345, "657"
    if(row.empty())
    {
        return false;
    }

    std::string all;
    // all = StringUtils::Join(" ", row);
    // std::cout << all << "  this is all " << std::endl;

    for(auto i : row)
    {
        for(auto j : i)
        {
            output.put(j);
            all += j;
        }        
    }

    std::cout << all << std::endl;
    

    // output.put(StringUtils::Join(" ", row));
    // output.write(row, )

    return true;



    // if(row.empty())
    // {
    //     return false;
    // }

    // for(auto i : row)
    // {
    //     for(auto j : i)
    //     {
    //         output.put(j);
    //     }
    // }
    // return true;
}