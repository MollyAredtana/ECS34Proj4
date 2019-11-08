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

TEST(CSVReader, SingleRow)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input(" 1,2 ,  3         ,4,5\x0d\x0a");
    CCSVReader Reader(input);
    std::vector<std::string> Row;

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 5);
    if(5 <= Row.size())
    {
        EXPECT_EQ(Row[0], "1");
        EXPECT_EQ(Row[1], "2");
        EXPECT_EQ(Row[2], "3");
        EXPECT_EQ(Row[3], "4");
        EXPECT_EQ(Row[4], "5");
    }
    EXPECT_TRUE(Reader.End());

}

TEST(CSVReader, MultipleRows)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input("I call our world Flatland,\x0a"
                     "not because we call it so,\x0a"
                     "but to make its nature clearer\x0a"
                     "to you, my happy readers,\x0a"
                     "who are privileged to live in Space.");
    CCSVReader Reader(input);
    std::vector<std::string> Row;
// try to get the size here, but it still need to delete the ' ' and the hexi nums so
// I skipped it since I knew the size is fine.
    // int length = 0;
    // input.seekg(0, input.end);
    // length = input.tellg();

    EXPECT_TRUE(Reader.ReadRow(Row));
    EXPECT_EQ(Row.size(), 115);
    // input.seekg(0, input.beg);
    if(5 <= Row.size())
    {
        EXPECT_EQ(Row[0], "I");
        EXPECT_EQ(Row[1], "c");
        EXPECT_EQ(Row[2], "a");
        EXPECT_EQ(Row[3], "l");
        EXPECT_EQ(Row[4], "l");
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
    std::vector<std::string> Row = {"1", "2", "3", "4", "5"};
    EXPECT_TRUE(Writer.WriteRow(Row));
}


TEST(CSVWriter, MultipleRows)
{
    std::stringstream output;
    CCSVWriter Writer(output);
    // confusion here :  can the writer read the numbers like 5 instad of "5"?
    std::vector<std::string> Row = {"1", "abc", "3", "\"abc\"", "5", "I", "w"};
    EXPECT_TRUE(Writer.WriteRow(Row));
}