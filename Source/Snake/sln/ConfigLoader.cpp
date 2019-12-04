#include "ConfigLoader.h"
#include <fstream>
#include <iterator>
#include <cassert>

File::File ()
	: m_fileString{ "" }, m_isLoaded{ false }
{}

/* Loads contents of given filepath into File object.
	Note! Successive loads will overwrite prior contents*/
void File::loadFile(const std::string& _fp)
{
	assert(_fp != "");	
	std::ifstream l_inFStream{ _fp };
	std::string l_fileContents{ std::istreambuf_iterator<char>(l_inFStream), std::istreambuf_iterator<char>() };
	assert(l_fileContents != "");

	m_fileString = l_fileContents;
	m_isLoaded = true;
	l_inFStream.close();
}
