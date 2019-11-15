#include "GameText.hpp"

ScreenText::ScreenText(std::string _string, const sf::Font& _font) : m_string{_string}, m_pFont{&_font}
{
	m_text.setFont(*m_pFont);
}
void ScreenText::setPosition(const sf::Vector2f& _pos)
{
	m_text.setPosition(_pos);
}
void ScreenText::draw(sf::RenderTarget& _window, sf::RenderStates _states) const
{
	_window.draw(m_text, _states);
}
std::string ScreenText::text() const
{
	return m_string;
}
