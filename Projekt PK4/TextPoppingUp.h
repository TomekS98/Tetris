#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextPoppingUp
{
	sf::Text _textmsg;
public:
	TextPoppingUp(sf::Font font);
	void textDraw(sf::RenderWindow &window);
	void setText(std::string textmsg);
	void makeTextTransparent();
};

