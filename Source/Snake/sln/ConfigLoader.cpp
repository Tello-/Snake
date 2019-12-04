#include "ConfigLoader.h"
#include <fstream>
#include <iterator>

ConfigLoader::ConfigLoader()
{
}

void ConfigLoader::loadFile(const std::string& _fp)
{
	assert(_fp != "");	
	std::ifstream l_inFStream{ _fp };
	std::string l_fileContents{ std::istreambuf_iterator<char>(l_inFStream), std::istreambuf_iterator<char>() };
	assert(l_fileContents != "");

	m_fileString = l_fileContents;
	l_inFStream.close();
}
