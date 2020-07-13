#pragma once
#include "SFML/Graphics.hpp"
#include "Bollean.h"
#include <list>
#include "Defines.h"
#include "GameMusic.h"


class Menu
{
	
	sf::Font font;
	std::list<sf::Text> menu;
	bool enterTheMenu; 
	int selectedItemIndex;
	int choicedItemIndex;

public:
	Menu();
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