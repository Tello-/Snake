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
		const std::string& contents() const { return m_fileString; }
		inline Config::Type fileType() const { return m_fileType; }

	private:
		std::string m_fileString;
		Config::Type m_fileType;
		bool m_isLoaded;
	};
}
