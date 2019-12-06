#include "../include/FileParser.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <fstream>
#include <exception>
#include <iostream>
#include <memory>



Config::FileParser::FileParser()
{}


/*	@Param: _assetType : type tag to be assigned to this asset file
	@Param: _filePath : string path to the file to be parsed
	Warning: Throws std::runtime_error on bad filepath */
Config::ParsedFile* Config::FileParser::Parse(const Config::AssetType & _assetType, const std::string & _filePath)
{
	/* Open provided file with ifstream */
	std::ifstream l_inStream{ _filePath };

	try 
	{
		/*rapidxml throws if it fails to read the stream. */
		/* using heap memory to avoid stack overflow warning */
		std::unique_ptr<rapidxml::file<>> lp_xmlFile(new rapidxml::file<>(l_inStream));
		/* l_doc will represent the head of the DOM tree holding the parsed xml info*/
		rapidxml::xml_document<> l_doc;
		/* parsing and pointing the l_doc pointer to the DOM head */
		l_doc.parse<0>(lp_xmlFile->data());


	}
	catch (std::runtime_error _exc)
	{
		l_inStream.close();
		throw _exc;
	}


	
	l_inStream.close();
	return nullptr;
}

