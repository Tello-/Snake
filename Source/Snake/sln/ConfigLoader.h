#pragma once

#include <string>

namespace Config
{
	enum Type { FONT };

	class File
	{
	public:
		File(Config::File::Type _fileType);
		void loadFile(const std::string& _fp);
		inline const std::string& contents() const { return m_fileString; }
		inline Config::Type fileType() const { return m_fileType; }
		inline bool isLoaded() const { return m_isLoaded; }

	private:
		std::string m_fileString;
		Config::Type m_fileType;
		bool m_isLoaded;
	};
}
