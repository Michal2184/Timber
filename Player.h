#pragma once
#include <SFML/Graphics.hpp>
#include "Side.h"

class Player1 {
public:
	// variables
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	//enum class side { LEFT, RIGHT, NONE };
	sf::Texture graveStoneTexture;
	sf::Sprite spriteRIP;
	sf::Texture axeTexture;
	sf::Sprite spriteAxe;
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;
	Side playerSide;

	Player1() {
		// constructor
		playerTexture.loadFromFile("graphics/player.png");
		playerSprite.setTexture(playerTexture);
		playerSprite.setPosition(580, 720);
		playerSide = Side::LEFT;
		// gravestone
		graveStoneTexture.loadFromFile("graphics/rip.png");
		spriteRIP.setTexture(graveStoneTexture);
		spriteRIP.setPosition(2600, 860);

		// axe
		axeTexture.loadFromFile("graphics/axe.png");
		spriteAxe.setTexture(axeTexture);
		spriteAxe.setPosition(AXE_POSITION_LEFT, 830);
	}

};