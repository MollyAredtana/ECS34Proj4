#include "XMLEntity.h"
#include <iostream>
#include "XMLReader.h"
#include "XMLWriter.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <fstream>
#include <string>


// logic

// 1-- we have couple csv files
// 2-- we read the csv files and the reader will put all those files into the istream
// 3-- we write the istream to a xml file
// 4-- we read the xml files and the xml files will output all the datas into the entity
// 5-- we write the entity to the proper form

// actual steps inside of the main.cpp
// 1-- we have the input already
// 2-- I will put them into the src temporarily
// 3-- use a way to call them and set those files to be the input 
// 4-- call CSVReader
// 5-- call CSVWriter
// 6-- call XMLReader
// 7-- call XMLWriter
// 8-- return 0

std::string Name();
char SEX();
int COUNT();
std::string line;
std::string name;
SXMLEntity Entity; // entity here
std::stringstream st;
std::stringstream total; // may be can used

std::vector <std::string> Buffer;

int main(int argc, char* argv[])
{
    std::cout << "  this is the main .cpp" << std::endl;
    // 1
    // CXMLReader Reader;
    std::string file = "smallmanifest.xml"; // I have to output a file and put it here in the end 
                            // but I have to do some functions to figure out the names 
                            // and ages and etc
    std::fstream s(file);
    // std::fstream s(file, s.binary | s.trunc | s.in | s.out);
    if(!s.is_open())
    {
        std::cout << "  Can not be opened  " << std::endl; 
    }

    st << s.rdbuf();
    s.close();

    std::cout << st.rdbuf() << std::endl;
    std::cout << st.good() << "  iii " << std::endl;

    CXMLReader Reader(st);
    Reader.ReadEntity(Entity);

    name = Entity.DNameData;
    std::cout << "  the name is   " << name << std::endl;




    // char x;
    // while(s.get(x))
    // {
    //     if(x != '\n')
    //     {
    //         line += x;
    //     }
    //     else{
    //         st.str(line);
    //         if(total.rdbuf()->in_avail() == 0)
                

    //         std::cout << st.rdbuf() << std::endl;
    //         line.clear();
            // SXMLEntity SX;
            
            // CXMLReader Reader(st);

            // Reader.ReadEntity(SX);

            // name = SX.AttributeValue("FILENAME"); // get the csv file name here.
            
            // std::cout << "   the name  is   " << name <<  "  " << SX.AttributeExists("FILENAME") << std::endl;
            

    //     }
    // }

    // std::cout <<  SX.DNameData << std::endl;



    

    
}



std::string Name() // The given name of the baby
{
    std::string inputName;
    std::string cp;
    std::cout << "  please enter a baby name  " << std::endl;
    std::cin >> inputName;

    // we have to do some reading here to search the specfic name here
     
    

}

char SEX() // The binary sex assigned at birth for the birth certificate (either M or F)
{

    // need to calculate the ratio here

    // take counts thing to here



}


int COUNT() // The number of babies of the assigned sex with the associated name born that year in that country
{
    // need to count the how many names here
    // like how popular is the name here



}