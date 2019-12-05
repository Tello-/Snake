#pragma once

#include <string>

/*Container for loading and storing text from a file*/
class TextFile
{
public:
	TextFile();
	void loadFile(const std::string& _fp);
	inline const std::string& contents() const { return m_fileString; }
	inline bool isLoaded() const { return m_isLoaded; }

private:
	std::string m_fileString;
	bool m_isLoaded;
};
