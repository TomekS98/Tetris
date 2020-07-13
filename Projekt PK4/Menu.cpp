#include "Menu.h"



Menu::Menu()
{
	if (!font.loadFromFile(FONT_PATH1))
	{
		return;
	}

	for (int i = 0; i < NUMBER_OF_CHOICES_IN_MENU; i++)
	{
		menu.push_back(sf::Text());
	}
	std::list<sf::Text>::iterator it = menu.begin();

	it->setFont(font);
	it->setFillColor(sf::Color::Red);
	it->setString("Play");
	it->setCharacterSize(124);
	it->setPosition(sf::Vector2f(WIDTH1 / 5+82, HEIGHT1 / (NUMBER_OF_CHOICES_IN_MENU + 1) * 0.5));

	it = std::next(it, 1);

	it->setFont(font);
	it->setFillColor(sf::Color::White);
	it->setString("Highscores");
	it->setCharacterSize(124);
	it->setPosition(sf::Vector2f(WIDTH1 / 5-25, HEIGHT1 / (NUMBER_OF_CHOICES_IN_MENU + 1) * 1.5));

	it = std::next(it, 1);

	it->setFont(font);
	it->setFillColor(sf::Color::White);
	it->setString("Exit");
	it->setCharacterSize(124);
	it->setPosition(sf::Vector2f(WIDTH1 / 5+82, HEIGHT1 / (NUMBER_OF_CHOICES_IN_MENU + 1) * 2.5));

	selectedItemIndex = 0;
	choicedItemIndex = 2;
	enterTheMenu = true;

}


void Menu::draw(sf::RenderWindow &window)
{
	std::list<sf::Text>::iterator it = menu.begin();

	for (; it != menu.end(); it++)
	{
		window.draw(*it);
	}
}

void Menu::MoveUp()
{
	std::list<sf::Text>::iterator it = std::next(menu.begin(), selectedItemIndex);

	if (selectedItemIndex - 1 >= 0)
	{
		it->setFillColor(sf::Color::White);
		selectedItemIndex--;
		it = std::prev(it, 1);
		it->setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	std::list<sf::Text>::iterator it = std::next(menu.begin(), selectedItemIndex);

	if (selectedItemIndex + 1 < NUMBER_OF_CHOICES_IN_MENU)
	{
		it->setFillColor(sf::Color::White);
		selectedItemIndex++;
		it = std::next(it, 1);
		it->setFillColor(sf::Color::Red);
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