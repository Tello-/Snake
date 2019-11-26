#include "MessageDatabase.h"

void MessageDatabase::createMessage(MessageType _type, sf::Font& _fontRef, const std::string& _string, unsigned _size)
{

	auto tempText = new sf::Text{_string,  _fontRef, _size };
	tempText->setFillColor(sf::Color::White);
	tempText->setOutlineColor(sf::Color::Black);
	m_messages.insert(messagePair{_type, tempText });
}

void MessageDatabase::addMessage(MessageType _messageType, sf::Text* _text)
{
	m_messages.insert(messagePair{_messageType, _text});
}
