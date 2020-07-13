#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Defines.h"

class TextPoppingUp
{
	sf::Font _fontTxt;
	sf::Text _textmsg;
public:
	TextPoppingUp();
	void textDraw(sf::RenderWindow *window);
	void setText(std::string textmsg);
	sf::Text getText() { return _textmsg; }
	void makeTextTransparent();
};

