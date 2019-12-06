#include "../include/FileParser.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <rapidxml_iterators.hpp>
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
		/*rapidxml throws std::runtime_error if it fails to read the stream. */
		/* using heap memory to avoid stack overflow warning */
		std::unique_ptr<rapidxml::file<>> lp_xmlFile(new rapidxml::file<>(l_inStream));
		/* l_doc will represent the head of the DOM tree holding the parsed xml info*/
		std::unique_ptr	<rapidxml::xml_document<>> lp_doc(new rapidxml::xml_document<>);		
		/* parsing and pointing the l_doc pointer to the DOM head */
		lp_doc->parse<0>(lp_xmlFile->data());

		/* Now to assign the parsed sections to the corresponding config::ParsedFile members: */
		assert(lp_doc->first_node); // assert that doc should have at least 1 node(font)
		
		rapidxml::node_iterator<> l_nodeIterator;


	}
	catch (std::runtime_error _exc)
	{
		l_inStream.close();
		throw _exc;
	}


	
	l_inStream.close();
	return nullptr;
}

