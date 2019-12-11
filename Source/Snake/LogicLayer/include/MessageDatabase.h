#pragma once
#include <map>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"


enum MessageType{PAUSE_SCREEN, SCORE, HIGHSCORE, LOSE_SCREEN};

using messagePair = std::pair<MessageType, sf::Text*>;
class MessageDatabase
{
public:
	   
	void				createMessage		(MessageType, const sf::Font&, const std::string&, unsigned = 24);
	void				addMessage			(MessageType, sf::Text*);
	sf::Text&			getMessage			(MessageType _type) { return *(m_messages.find(_type)->second); }


private:
	std::map<MessageType,sf::Text*> m_messages;
};

