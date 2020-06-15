#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextPoppingUp
{
	sf::Font _fontTxt;
	sf::Text _textmsg;
public:
	TextPoppingUp();
	void textDraw(sf::RenderWindow &window);
	void setText(std::string textmsg);
	void makeTextTransparent();
};

