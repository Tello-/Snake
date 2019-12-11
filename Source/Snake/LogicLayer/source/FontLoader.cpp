#include "..\include\FontLoader.h"
#include <vector>
#include "../../ApplicationLayer/include/FontPool.h"

Config::FontLoader::FontLoader()
{
}

FontPool* Config::FontLoader::load(const std::string& _fp)
{
	std::vector<Config::ParsedFile*> l_parsedVector;
	Config::FileParser::Parse(Config::AssetType::Font, _fp, l_parsedVector);
	FontPool* lp_newPool = new FontPool;
	for (auto file : l_parsedVector)
	{
		lp_newPool->createFont(file->key, file->filePath);
	}
	return lp_newPool;
}
