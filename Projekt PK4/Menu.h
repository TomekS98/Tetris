#pragma once
#include "SFML/Graphics.hpp"
#include "Bollean.h"
#include <list>
#include "Defines.h"


class Menu
{
	int selectedItemIndex;
	int choicedItemIndex;
	sf::Font font;
	std::list<sf::Text> menu;
	bool enterTheMenu;

public:
	Menu(float width, float height);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
	void MenuController(sf::RenderWindow &window);
	void changeTheStateOfEnter(Bollean stateOfBool);
	bool getTheStateOfEnter();
	int getChoicedItemIndex();
	void setChoicedItemIndex(int value);

};