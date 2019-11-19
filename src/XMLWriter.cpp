#include "XMLWriter.h"
#include "XMLEntity.h"
#include <string>


CXMLWriter::CXMLWriter(std::ostream &os) : DOutput(os)
{
}
CXMLWriter::~CXMLWriter()
{
}
    
// Outputs all end elements for those that have been started
bool CXMLWriter::Flush()
{
	std::string EndName;
	while(Elements.size() != 0){
		std::string EndName = "</" + Elements.top() + ">";
		Elements.pop();
		DOutput << EndName;
	}
	
	return true;
}


// Writes out the entity to the output stream
bool CXMLWriter::WriteEntity(const SXMLEntity &entity)
{
	std::string StringOutput;
	
	//checks the entity, pushes to stack if start, pops if end
	if(entity.DType == SXMLEntity::EType::StartElement){
		Elements.push(entity.DNameData);
		StringOutput = "<" + entity.DNameData + ">";
		DOutput << StringOutput;
		return true;
	} else if(entity.DType == SXMLEntity::EType::EndElement){
		Elements.pop();
		StringOutput = "</" + entity.DNameData + ">";
		DOutput << StringOutput;
		return true;
	} else if(entity.DType == SXMLEntity::EType::CompleteElement){
		StringOutput = "<" + entity.DNameData + "/>";
		DOutput << StringOutput;
		return true;
	} else if(entity.DType == SXMLEntity::EType::CharData){
		StringOutput = entity.DNameData;
		DOutput << StringOutput;
		return true;
	}

	
	return false;
}