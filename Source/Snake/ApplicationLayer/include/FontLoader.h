/* This file holds the interace for loading font data from the config file and then using
the data to create/load fonts into the font pool*/
#include "../../ApplicationLayer/include/FileParser.h"

class FontPool;
namespace Config
{	
	class FontLoader
	{
	public:
		FontLoader();
		FontPool* load(const std::string& _fp);
	};
}