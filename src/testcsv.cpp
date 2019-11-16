#include <gtest/gtest.h>
#include "CSVReader.h"
#include "CSVWriter.h"
#include <sstream>


TEST(CSVReader, Emptyfile)
{
    std::stringstream input;
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_FALSE(Reader.ReadRow(Row));

    EXPECT_TRUE(Reader.End());


}

TEST(CSVReader, SingleRow1)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input("\"I call our world Flatland\",\x0a");
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 2);
    if(5 <= Row.size())
    {
        EXPECT_EQ(Row[0], "I call our world Flatland");
        EXPECT_EQ(Row[1], ",");
        // EXPECT_EQ(Row[1], "2");
        // EXPECT_EQ(Row[2], "3");
        // EXPECT_EQ(Row[3], "4");
        // EXPECT_EQ(Row[4], "5");
        // EXPECT_EQ(Row[6], "9");// should it be 99 or 
        // EXPECT_EQ(Row[7], "a");
    }
    EXPECT_TRUE(Reader.End());

}


// ",,,,,\x0a"
TEST(CSVReader, SingleRow2)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input(",,,,,\x0a");
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 6);
    if(0 <= Row.size())
    {
        EXPECT_EQ(Row[0], "");
        EXPECT_EQ(Row[1], "");
       
    }
    EXPECT_TRUE(Reader.End());

}


TEST(CSVReader, MultipleRows)
{
    std::cout << "\"I call our world Flatland,\x0a"
                       "not because we call it so,\x0a"
                       "but to make its nature clearer\x0a"
                       "to you, my happy readers,\x0a"
                       "who are privileged to live in Space.\"" << std::endl;
    

    std::stringstream input("\"I call our world Flatland,\x0a"
                       "not because we call it so,\x0a"
                       "but to make its nature clearer\x0a"
                       "to you, my happy readers,\x0a"
                       "who are privileged to live in Space.\"");
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 1);
    EXPECT_EQ(Row[0], "I call our world Flatland,\nnot because we call it so,\nbut to make its nature clearer\nto you, my happy readers,\nwho are privileged to live in Space.");

    EXPECT_TRUE(Reader.End());

}

TEST(CSVReader, longnumbers)
{
    

    std::stringstream input("12345678901234567890123456789012");
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 1);

    if(0 <= Row.size())
    {
        EXPECT_EQ(Row[0], "12345678901234567890123456789012");
       
    }

    EXPECT_TRUE(Reader.End());

}



TEST(CSVWriter, Emptyfile)
{
    std::stringstream output;
    CCSVWriter Writer(output);
    std::vector<std::string> Row;
    EXPECT_FALSE(Writer.WriteRow(Row));
}


TEST(CSVWriter, SingleRow)
{
    std::stringstream output;
    CCSVWriter Writer(output);
    std::vector<std::string> Row = {"1, 2, 3,\x0a\x0d\x0a  \"4\", \x0d\"\""};    
    EXPECT_TRUE(Writer.WriteRow(Row));
    // "1,2,3,4,5"
}


TEST(CSVWriter, MultipleRows)
{
    std::stringstream output;
    CCSVWriter Writer(output);
    // confusion here :  can the writer read the numbers like 5 instad of "5"?
    std::vector<std::string> Row = {"\"I call our world Flatland,\x0a"
                       "not because we call it so,\x0a"
                       "but to make its nature clearer\x0a"
                       "to you, my happy readers,\x0a"
                       "who are privileged to live in Space.\""};
    EXPECT_TRUE(Writer.WriteRow(Row));
}


