#include "XMLEntity.h"
#include <iostream>
#include "XMLReader.h"
#include "XMLWriter.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <fstream>
#include <string>
#include "StringUtils.h"
#include "Path.h"


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

int main(int argc, char * argv[])
{
    
    
    std::cout << "  this is the main .cpp" << std::endl;
    // 1
    // CXMLReader Reader;
    std::string file = argv[1]; // I have to output a file and put it here in the end 
                            // but I have to do some functions to figure out the names 
                            // and ages and etc
    std::ifstream s(file);
    // std::fstream s(file, s.binary | s.trunc | s.in | s.out);
    if(!s.is_open())
    {
        std::cout << "  Can not be opened  " << std::endl; 
    }
    CXMLReader Reader(s);

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
                std::fstream CF;
                std::string pa = "proj4data/";
                // std::string AndPath = "proj4data/" + CSVFile;
                std::string AndPath = CPath::CurrentPath() + pa + CSVFile;
                std::cout << AndPath << std::endl;
                CF.open(AndPath, std::fstream::in | std::fstream::out);
                std::vector <std::string> row;
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



// while(1){

// 		std::vector<std::vector <std::string> > Final = { {"All", "", "", ""}
// 														  {"England", "", "", ""}
// 														  {"Ireland", "", "", "",}
// 														  {"Northern Ireland", "", "", ""}
// 														  {"Scotland", "", "", ""}
// 														  {"United States", "", "", ""}
// 														}

// 		BabyName = GetName();
// 		//Function to send babyname through csvhell
		
		
		
// 		//Modifies the count
// 		int rowcount = 1;
// 		int MaleCount = 0;
// 		int FemaleCount = 0;
// 		int TempYearCount = 0;
// 		int OverallCount = 0;
		
// 		if(row[1] == "F"){
// 			//then check the next row for baby names, if there is another one get next row of males
// 			rowcount = 2;
// 		}
		
// 		if(rowcount == 1){
// 			if(row[1] == "F"){
// 				FemaleCount += row[2];
// 				OverallCount += row[2];
				
// 			} else{
// 				MaleCount += row[2];
// 				OverallCount += row[2];
// 			}
// 		} else{
// 			FemaleCount += row[2];
// 			MaleCount += row2[2];
// 			OverallCount = OverallCount + row[2] + row2[2];
// 		}
		
		
// 		//checks the middle year
// 		int Average3Year[3];
// 		int Iterate3 = 0;	
// 		int Highest3YearAverage = 0;
// 		int Temp3YearAverage = 0;
		
// 		std::string MiddleYear;
// 		Average3Year[Iterate3%3] = MaleCount + FemaleCount;
// 		Temp3YearAverage = (Average3Year[0] + Average3Year[1] + Average3Year[2])/3;
		
// 		if(Highest3YearAverage < Temp3YearAverage){
// 			Highest3YearAverage = Temp3YearAverage;
// 			int temp = stoi(year);
// 			MiddleYear = tostring(temp - 1);
// 		}
		
// 		Iterate3++;
		
		
		
// 		//reveals probabilty of boy or girl
// 		Double Probabilty;
// 		if(MaleCount < FemaleCount){
// 			Probabilty = (FemaleCount/Overall) * 100;
			
// 		} else {
// 			Probability = (MaleCount/Overall) * 100;
// 		}
		
		
		
// 		//Construct All Cout
// 		int MalePool;
// 		int FemalePool;
// 		int Pool = MalePool + FemalePool;
// 		//these are all the males and females over the years
		
// 		if(MalePool < FemalePool){
// 			Final[0][1] = "F";
// 			Final[0][2] = tostring((FemalePool/Pool) * 100;); 
// 		} else {
// 			Final[0][1] = "M";
// 			Final[0][2] = tostring(()MalePool/Pool) * 100);
// 		}
		
		
		
// 		//Cout Portion		
// 		for(int i = 0; i < Final.size(); i++){
// 			std::cout << Final[i][0] << ": " << Final[i][1] << " (" << Final[i][2] << "%) " << Final[i][3];
// 		}
// 	}

    

    
// }



// std::string GetName() // The given name of the baby
// {
// 	std::string NameInput;
// 	std::cout << "Enter name> ";
// 	std::cin << NameInput;
// 	Name = StringUtils::Capitilize(NameInput);
     
//     return Name;

// }

// char SEX()
// {
// 	double Probabilty;
// 	if(MaleCount < FemaleCount){
// 		Probabilty = (FemaleCount/Overall) * 100;
		
// 	} else {
// 		Probability = (MaleCount/Overall) * 100;
// 	}
// }


// int COUNT(std::vector<std::string> row)
// {
// 	if(row[1] == "F"){
// 		//then check the next row for baby names, if there is another one get next row of males
// 		rowcount = 2;
// 	}
	
// 	if(rowcount == 1){
// 		if(row[1] == "F"){
// 			FemaleCount += row[2];
// 			OverallCount += row[2];
			
// 		} else{
// 			MaleCount += row[2];
// 			OverallCount += row[2];
// 		}
// 	} else{
// 		FemaleCount += row[2];
// 		MaleCount += row2[2];
// 		OverallCount = OverallCount + row[2] + row2[2];
// 	}
// }