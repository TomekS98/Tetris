#include "Display.h"

#include <iostream>

int main()
{
	srand(time(NULL));
	GameController gameController(BlocksGenerator(0, 0), PlayField());
	Textures bg_texture(BACKGROUND_PATH);
	Textures tiles_texture(TILES_PATH);
	Textures frame_pion(FRAME_PION_PATH);
	frame_pion.setPositionOfSprite(315, 0);
	Textures frame_poziom(FRAME_POZIOM_PATH);
	frame_poziom.setPositionOfSprite(0, 635);
	Textures menu_bg(MENU_PATH);
	Textures top5_bg(TOP5_PATH);
	Textures tabOfTextures[NUMBER_OF_TEXTURES] = { tiles_texture,bg_texture, frame_pion,frame_poziom,menu_bg,top5_bg };
	Display _display(tabOfTextures, gameController);
	
	while (_display.checkIfWindowIsOpen())
	{
		try
		{
			if (_display.getMenu().getTheStateOfEnter()) {
				if (!_display.getGameMusic().getTheStateOfPlayMusic() || _display.getGameMusic().getMusicString() == "Game")
				{
					_display.getGameMusic().inMenuMusic();
				}
				_display.displayMenu();
			}
			if (_display.getMenu().getChoicedItemIndex() == 0)
			{
				if (!_display.getGameMusic().getTheStateOfPlayMusic() || _display.getGameMusic().getMusicString() == "Menu")
				{
					_display.getGameMusic().inGameMusic();
				}
				_display.displayGame();
			}
			else if (_display.getMenu().getChoicedItemIndex() == 1)
			{
				_display.displayScores();
			}
		}
		catch(const std::exception & varOfexc)
		{
			std::cout << "catched exception: ";
			std::cout << varOfexc.what();
		}
	}
	return 0;
}
