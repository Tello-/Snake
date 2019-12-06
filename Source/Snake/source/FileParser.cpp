#include "../include/FileParser.h"
#include <memory>


Config::FileParser::FileParser()
{}

Config::ParsedFile* Config::FileParser::Parse(const Config::AssetType & _assetType, const TextFile & _textFile)
{	
	// TODO: run text file through RapidXML code and parse out the data to fill out the ParsedFile struct to return as a pointer.
}
