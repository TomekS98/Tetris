#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("fonts/font.ttf"))
	{
		return;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(124);
	menu[0].setPosition(sf::Vector2f(width / 5+82, height / (NUMBER_OF_CHOICES + 1) * 0.5));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Highscores");
	menu[1].setCharacterSize(124);
	menu[1].setPosition(sf::Vector2f(width / 5-25, height / (NUMBER_OF_CHOICES + 1) * 1.5));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(124);
	menu[2].setPosition(sf::Vector2f(width / 5+82, height / (NUMBER_OF_CHOICES + 1) * 2.5));

	selectedItemIndex = 0;
	enterTheMenu = true;
}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < NUMBER_OF_CHOICES; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < NUMBER_OF_CHOICES)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
int Menu::GetPressedItem()
{
	 return selectedItemIndex; 
}

void Menu::MenuController(sf::RenderWindow &window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->MoveUp();
				break;

			case sf::Keyboard::Down:
				this->MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (this->GetPressedItem())
				{
				case 0:
					choicedItemIndex = 0;
					this->changeTheStateOfEnter(Bollean::False);
					break;
				case 1:
					choicedItemIndex = 1;
					this->changeTheStateOfEnter(Bollean::False);
					break;
				case 2:
					window.close();
					break;
				}
				break;
			}
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Menu::changeTheStateOfEnter(Bollean stateOfBool)
{
	switch (stateOfBool)
	{
	case True:
		enterTheMenu = true;
		break;
	case False:
		enterTheMenu = false;
		break;
	default:
		break;
	}
}

bool Menu::getTheStateOfEnter()
{
	return enterTheMenu;
}

int Menu::getChoicedItemIndex()
{
	return choicedItemIndex;
}

void Menu::setChoicedItemIndex(int value)
{
	choicedItemIndex = value;
}