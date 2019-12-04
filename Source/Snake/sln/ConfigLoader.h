#pragma once

#include <string>
#include <rapidxml.hpp>

namespace ConfigFile
{
	enum Type{FONT};
}
class ConfigLoader
{
public:
	ConfigLoader();
	void loadFile(const std::string& _fp);
private: // private methods


private:
	std::string m_fileString;
};

