#include "../ApplicationLayer/FileParser.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <fstream>
#include <exception>
#include <memory>



Config::FileParser::FileParser()
{}


/*	@Param: _assetType : type tag to be assigned to this asset file
	@Param: _filePath : string path to the file to be parsed
	@Param: _fileVec : a mutable vector that the function will fill with any config files created
	Warning: Throws std::runtime_error on bad filepath */
void Config::FileParser::Parse(const Config::AssetType & _assetType, const std::string & _filePath, std::vector<Config::ParsedFile*>& _fileVec)
{
	/* Open provided file with ifstream */
	std::ifstream l_inStream{ _filePath };

	try 
	{
		/*rapidxml throws std::runtime_error if it fails to read the stream. */
		/* using heap memory to avoid stack overflow warning */
		std::unique_ptr<rapidxml::file<>> lp_xmlFile(new rapidxml::file<>(l_inStream));
		/* l_doc will represent the head of the DOM tree holding the parsed xml info*/
		std::unique_ptr	<rapidxml::xml_document<>> lp_doc(new rapidxml::xml_document<>);		
		/* parsing and pointing the l_doc pointer to the DOM head */
		lp_doc->parse<0>(lp_xmlFile->data());

		/* Now to assign the parsed sections to the corresponding config::ParsedFile members: */
		//assert(lp_doc->first_node); // assert that doc should have at least 1 node(font)
		
		// iterate through all fonts
		for (auto nodeIter = lp_doc->first_node()->first_node(); nodeIter; nodeIter = nodeIter->next_sibling())
		{
			auto newFile = new ParsedFile;
			newFile->name = nodeIter->first_attribute()->value;
			newFile->key = nodeIter->first_node()->value();
			newFile->filePath = nodeIter->first_node()->next_sibling()->value();
			newFile->type = _assetType;
			_fileVec.push_back(newFile);
		}
	}
	catch (std::runtime_error _exc)
	{
		l_inStream.close();
		throw _exc;
	}
	
	l_inStream.close();
}

