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
std::string Attri;
std::string Value;
std::string name;
SXMLEntity Entity; // entity here
std::stringstream st;


std::vector <std::string> Country;
std::vector <std::string> Year;

int main()
{
    std::cout << "  this is the main .cpp" << std::endl;
    // 1
    // CXMLReader Reader;
    std::string file = "smallmanifest.xml"; // I have to output a file and put it here in the end 
                            // but I have to do some functions to figure out the names 
                            // and ages and etc
    std::ifstream s(file);
    // std::fstream s(file, s.binary | s.trunc | s.in | s.out);
    if(!s.is_open())
    {
        std::cout << "  Can not be opened  " << std::endl; 
    }
    CXMLReader Reader(s);
    // Reader.ReadEntity(Entity);

    // name = Entity.DNameData;

    // std::cout << "  the name is " << name  << std::endl;
    // the names for each attribute is different, so we have to use the DAttributes 
    // which is a vector and go through everything inside of it
    // like   Entity.DAttributes.front().first   to find the key name
    // country="ENG"
    //  key     value
    //    Attribute

    std::pair< std::string, std::string > first;
    std::string str2(".csv");
    Reader.ReadEntity(Entity); // skip the root
    while(!Reader.End())
    {
        Reader.ReadEntity(Entity);
        while(!Entity.DAttributes.empty())
        {
            first = Entity.DAttributes.front();
            // Attri = Entity.AttributeValue(first.first);// key
            Value = Entity.DAttributes.front().second; //  value
            Entity.DAttributes.erase(Entity.DAttributes.begin());
            std::pair< std::string, std::string > first; // renew it


            std::string CSVFile = Value;
            if(CSVFile.find(str2) != std::string::npos) // found
            {
                std::ifstream CF(CSVFile.c_str());
                // CF.open(CSVFile, std::ifstream::in);
                std::vector <std::string> row;
                std::cout << CSVFile << std::endl;
                if(CF.good())
                {
                    std::cout << "   gooooooooood  " << std::endl;
                }
                else{
                    std::cout << "   badddddd    " << std::endl;
                }
                if(!CF.is_open())
                {
                    std::cout << "  Can not be opened  " << std::endl; 
                }
                else
                {
                    CCSVReader CS(CF);
                    CS.ReadRow(row);
                    CF.close();

                }
            }
            else
            {
                if(!Value.find_first_of("0123456789") != std::string::npos)// not digit
                {
                    // std::cout << Value << std::endl;;
                    Country.push_back(Value);

                }
                else
                {
                    // std::cout << Value << std::endl;
                    Year.push_back(Value);
                }
                

            }                

        
            
            // if(!Attri.find_first_of("0123456789") != std::string::npos) // no digit 
            // 自己会把所有read 完 不像 xml /// it stuck in a infinite loop here 
            // 在这里我们已经把所有东西都写进 row 里了, row 是一个 vector of strings
            // call helper functions here 
            // helper functions should return somethings
        }
    }


    // 也许要做两个while loop 一个去查整体的entity 完结了没有
    // 还有一个while loop 要查每一个 name tag的 Dattributes 有没有走完
    // 就像是csv 和 xml一样要 pop front 

    // 👌  I am going to do a sudo here
    // 
    //   std::string first //   可以移到最上面
    //   std::stringstream CI//   可以移到最上面
    // while(Entity not finished)    which means you still can do ReadEntity()
    //{
    //      while(!Entity.DAttributes.empty())
    //      {
    //          first = Entity.DAttributes.front();
    //key name: Attri = Entity.AttributeValue(first.first); // ex :{{1, 2}} first.first = 1
    //          Entity.DAttributes.erase(0) // so we get rid of the first one
    //          
    //          and it will just keep going until we hit the end...
    //
    //          since we have the attri which is the key name here
    //          then we can do the CSVReader here.
    //              
    //           going to make it to a fstream here
    //           std::string CSVfile = Attri; // s
    //           std::fstream C(CSVfile); // opened
    //
    //
    //           std::vector <std::string> row;
    //           CCSVReader CS(C);  input 
    //           CS.ReadRow(& row);
    //           // then call helper functions here.
    //      
    //       }


    

    
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