#include "../../ApplicationLayer/include/FontPool.h"

void FontPool::createFont(const std::string& _key, const std::string& _filePath)
{
	auto tempFontPointer = new sf::Font;
	if (!tempFontPointer->loadFromFile("../../../Assets/Font/Nunito_Sans/NunitoSans-Bold.ttf"))
	{
		throw std::runtime_error{ "Failed to load font at expected filepath : " + _filePath };
	}
	else
	{
		m_fonts.insert(std::pair<std::string, sf::Font*>{_key, tempFontPointer});
		m_bIsEmpty = false;
		tempFontPointer = nullptr;
	}
}

bool FontPool::removeFont(const std::string& _key)
{
	if (!findFont(_key))
	{
		return false;
	}
	else
	{
		m_fonts.erase(_key);
		return true;
	}
}

const sf::Font& FontPool::getFont(const std::string& _targetFont) const
{
	auto found = m_fonts.find(_targetFont);
	assert(found != m_fonts.end());
	return *found->second;
}

bool FontPool::findFont(const std::string& _targetFont) const
{
	auto it = m_fonts.find(_targetFont);
	return it != m_fonts.end();
}
const std::vector<std::string> FontPool::fontKeyList() const
{
	std::vector<std::string> keyVector;
	for (auto it = m_fonts.begin(); it != m_fonts.end(); ++it)
	{
		keyVector.push_back(it->first);
	}
	return keyVector;
}
