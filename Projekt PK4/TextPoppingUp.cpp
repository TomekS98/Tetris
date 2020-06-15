#include "TextPoppingUp.h"
TextPoppingUp::TextPoppingUp()
{
	if (!_fontTxt.loadFromFile("fonts/font.ttf"))
	{
		return;
	}
	_textmsg.setFont(_fontTxt);
	_textmsg.setString("0");
	_textmsg.setCharacterSize(64);
	_textmsg.setFillColor(sf::Color::White);
	_textmsg.setPosition(140, 340);
}
void TextPoppingUp::textDraw(sf::RenderWindow & window)
{
	window.draw(_textmsg);
}
void TextPoppingUp::setText(std::string textmsg)
{
	_textmsg.setString(textmsg);
}

void TextPoppingUp::makeTextTransparent()
{
	_textmsg.setFillColor(sf::Color::Transparent);
}
