#pragma once
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"


class ScreenText 
	: public sf::Drawable, public sf::NonCopyable
{
public:

	ScreenText(std::string _string, const sf::Font& _font);

	void setPosition(const sf::Vector2f&);
	const sf::Vector2f& getPosition() const { return m_text.getPosition(); }

	void draw(sf::RenderTarget&, sf::RenderStates) const override;

	std::string text() const;

private: // Private Methods



private: // Private Data
	std::string m_string;
	sf::Text m_text;
	const sf::Font* m_pFont;
};