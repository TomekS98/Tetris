#pragma once
#include "SFML/Graphics.hpp"
#include "Bollean.h"
#define NUMBER_OF_CHOICES 3

class Menu
{
	int selectedItemIndex;
	int choicedItemIndex;
	sf::Font font;
	sf::Text menu[NUMBER_OF_CHOICES];
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