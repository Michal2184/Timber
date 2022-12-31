#pragma once

#include <SFML/Graphics.hpp>


class Tree {
public:
	sf::Texture textureTree;
	sf::Sprite spriteTree;
	sf::Texture textureLog;
	sf::Sprite spriteLog;
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;

	Tree() {
		// create a tree: texture + sprite + position
		textureTree.loadFromFile("graphics/tree.png");
		spriteTree.setTexture(textureTree);
		spriteTree.setPosition(810, 0);

		// log
		textureLog.loadFromFile("graphics/log.png");
		spriteLog.setTexture(textureLog);
		spriteLog.setPosition(810, 720);

	}

	void moveLog(sf::Time dt) {
		spriteLog.setPosition(spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
			spriteLog.getPosition().y + (logSpeedY * dt.asSeconds())/2);
		if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
			logActive = false;
			spriteLog.setPosition(810, 720);
		}
	}
};
