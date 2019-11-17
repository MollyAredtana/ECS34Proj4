#include <gtest/gtest.h>
#include "XMLReader.h"
#include "XMLWriter.h"
#include <sstream>


TEST(XMLReader, Emptyfile)
{
    std::stringstream input;
    CXMLReader Reader(input);
    EXPECT_TRUE(Reader.End());


}

TEST(XMLReader, Simpletest)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input("<ppp><other></other></ppp>");
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;

    CXMLReader Reader(input);

    SXMLEntity Entity;

    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.End());

}

TEST(XMLReader, ComplexTest)
{
    std::stringstream input("<ppp><other>hhh</other></ppp>"); // abc=\"dfg\"
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;

    CXMLReader Reader(input);

    SXMLEntity Entity;

    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    // EXPECT_TRUE(Entity.AttributeExists(Entity.DNameData));
    // EXPECT_EQ(Entity.AttributeValue(Entity.DNameData), "dfg");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::CharData);
    EXPECT_EQ(Entity.DNameData, "hhh");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.End());
}


TEST(XMLReader, MoreComplexTest)
{
    std::stringstream input("<ppp abc=\"dfg\"><other></other></ppp>"); // abc=\"dfg\"
    CXMLReader Reader(input);
    SXMLEntity Entity;

    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Entity.AttributeExists("abc"));
    EXPECT_EQ(Entity.AttributeValue("abc"),"dfg");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.End());
}


TEST(XMLReader, MoreMoreComplexTest)
{
    std::stringstream input("<ppp abc=\"dfg\"><other>hhh</other></ppp>"); // abc=\"dfg\"
    CXMLReader Reader(input);
    SXMLEntity Entity;

    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Entity.AttributeExists("abc"));
    EXPECT_EQ(Entity.AttributeValue("abc"),"dfg");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::CharData);
    EXPECT_EQ(Entity.DNameData, "hhh");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.End());
}


TEST(XMLReader, SuperComplexTest)
{
    std::stringstream input("<ppp abc=\"dfg\" cln=\"idol\" ><other>hhh</other></ppp>"); // abc=\"dfg\"
    CXMLReader Reader(input);
    SXMLEntity Entity;

    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Entity.AttributeExists("abc"));
    EXPECT_EQ(Entity.AttributeValue("abc"),"dfg");
    EXPECT_TRUE(Entity.AttributeExists("cln"));
    EXPECT_EQ(Entity.AttributeValue("cln"),"idol");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_FALSE(Reader.End());
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::CharData);
    EXPECT_EQ(Entity.DNameData, "hhh");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.End());
}

TEST(XMLReader, skip1)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input("<ppp><other></other></ppp>");
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;

    CXMLReader Reader(input);

    SXMLEntity Entity;

    EXPECT_FALSE(Reader.ReadEntity(Entity, true));
    EXPECT_FALSE(Reader.ReadEntity(Entity, true));
    EXPECT_FALSE(Reader.ReadEntity(Entity, true));
    EXPECT_FALSE(Reader.ReadEntity(Entity, true));
    EXPECT_TRUE(Reader.End());

}

TEST(XMLReader, skip2)
{
    // " 1,2 ,  3         ,4,5\x0d\x0a";

    std::stringstream input("<ppp><other><jjj></jjj></other></ppp>");
    // std::cout << "\"I call our world Flatland\",\x0a" << std::endl;

    CXMLReader Reader(input);

    SXMLEntity Entity;

    EXPECT_FALSE(Reader.ReadEntity(Entity, true));
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "ppp");
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "other");
    EXPECT_FALSE(Reader.End());

}


TEST(XMLWriter, Emptyfile)
{
    
}


TEST(XMLWriter, SimpleTest)
{
    std::stringstream output;
    
}


TEST(XMLWriter, ComplexTest)
{
    std::stringstream output;
    
}