// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <SDL.h>
#include "Renderer.h"
#include "SpriteManager.h"
#include "UnitGrid.h"
#include "Drawer.h"


int main(int argc, char *argv[])
{
	
	try {
		engine::render::Renderer renderer;
		game::graphics::Drawer drawer(&renderer);
		
		
		auto tex = renderer.loadTexture("res/spritesheets/weapons.png");

		SDL_Rect axeSource = { 64,0,64,64 };
		engine::render::Sprite axeSprite = { tex, axeSource };
		auto axe = std::make_shared<game::combat::Unit>(axeSprite);

		SDL_Rect bowSource = { 0,64,64,64 };
		engine::render::Sprite bowSprite = { tex, bowSource };
		auto bow = std::make_shared<game::combat::Unit>(bowSprite);

		game::combat::UnitGrid allyUnitGrid;
		allyUnitGrid.addUnit(0, 0, bow);
		allyUnitGrid.addUnit(1, 1, axe);
		allyUnitGrid.addUnit(2, 1, axe);

		game::combat::UnitGrid enemyUnitGrid;
		enemyUnitGrid.addUnit(0, 0, axe);
		enemyUnitGrid.addUnit(1, 0, axe);
		enemyUnitGrid.addUnit(2, 0, axe);
		enemyUnitGrid.addUnit(1, 1, bow);
		enemyUnitGrid.addUnit(2, 1, bow);

		drawer.drawUnitGrid(allyUnitGrid, 100, 100, 200, 300);
		drawer.drawUnitGrid(enemyUnitGrid,400,100,200,300);
		
		renderer.renderPresent();
		SDL_Delay(2000);
	}
	catch (const engine::render::SDLException ex) {
		std::cout << ex.message << std::endl;
	}
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
