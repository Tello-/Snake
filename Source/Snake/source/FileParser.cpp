#include "../include/FileParser.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <fstream>
#include <exception>
#include <iostream>
#include <memory>



Config::FileParser::FileParser()
{}

Config::ParsedFile* Config::FileParser::Parse(const Config::AssetType & _assetType, const std::string & _filePath)
{
	/* Open provided file with ifstream */
	std::ifstream l_inStream{ _filePath };

	try 
	{
		/*rapidxml throws if it fails to read the stream. */
		/* using heap memory to avoid stack overflow warning */
		std::unique_ptr<rapidxml::file<>> xmlFile(new rapidxml::file<>(l_inStream));
	}
	catch (std::runtime_error _exc)
	{
		l_inStream.close();
		throw _exc;
	}


	rapidxml::xml_document<> l_doc{};
	l_inStream.close();
	return nullptr;
}

