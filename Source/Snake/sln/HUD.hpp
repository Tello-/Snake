#pragma once
#include <SFML/Graphics.hpp>
class HUD : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private:

};

