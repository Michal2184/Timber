#pragma once
#include <SFML/Graphics.hpp>


class Backgroud {
public:
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	Backgroud() {
		// create a background: texture + sprite + position
		textureBackground.loadFromFile("graphics/background.png");
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);
	}
};