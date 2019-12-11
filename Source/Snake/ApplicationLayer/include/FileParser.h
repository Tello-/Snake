/* File parser is what takes the TextFile object and separates the XML nodes into separate pieces of data.

	The thing is.. I'm not quite sure how I want to handle this yet. There are at least a few kinds of XML config file types.
	
	Font Config, Image Config, Sound Config... I don't think inheritance is the correct route. My first instinct keeps tell me to 
	make a general FileParser interface and then to inherit this interface for each of the 3 types of XML files to parse. This makes me 
	feel like this sends the message that these 3 types of files are interchangable and suitable for polymorphism somewhere... However, why
	would a single system need a generic FileParser object and then manipulate or deal with one of these derived classes?*/

#pragma once
#include <string>
#include <vector>

namespace Config
{
	enum class AssetType {Font};
	struct ParsedFile
	{
		Config::AssetType type;
		std::string name;
		std::string key;
		std::string filePath;
	};
	class FileParser
	{
	public:
		FileParser() = delete;
	private:
		friend class FontLoader;
		static void Parse(const Config::AssetType& _assetType, const std::string& _filePath, std::vector<Config::ParsedFile*>& _fileVec);
	};

}