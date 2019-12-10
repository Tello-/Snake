/* This is the file containing the header information for the FontPool Class.

	The FontPool is the container that holds all of the games fonts or whatever collection of fonts you need.
	Said fonts are accessable via a key/value relationship where the key is a string and the value is the sf::Font */
#pragma once
#include <map>
#include <string>
#include <vector>
#include <cassert> // for assert()
#include <SFML/Graphics/Font.hpp>


/* Container for storage/access of all fonts used in the app*/
class FontPool
{
public:
	FontPool() : m_bIsEmpty{ true } {}
	void createFont(const std::string& _key, const std::string& _filePath);
	bool removeFont(const std::string& _key);
	const sf::Font& getFont(const std::string&) const;
	bool findFont(const std::string& _targetFont) const;
	const std::vector<std::string> fontKeyList() const;
	
	inline bool isEmpty() const { return m_bIsEmpty; }
private:
	std::map<std::string, sf::Font*> m_fonts;
	bool m_bIsEmpty;
};