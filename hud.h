
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <cmath>

class Hud {
public:
	// score
	sf::Font font;
	sf::Text messageText;
	sf::Text scoreText;
	sf::Text title;
	sf::Text timeDisplay;
	sf::Text gameTimeText;
	sf::Text infoText;
	// timebar
	sf::RectangleShape timeBar;
	sf::Time gameTimeTotal;
	int score;
	float timeBarStartWidth = 400;
	float timeBarHight = 30;
	float timeRemaining = 6.0f;
	float timeWidthPerSecond;

	Hud() {
		// score board construtor
		font.loadFromFile("fonts/KOMIKAP_.ttf");
		messageText.setFont(font);
		messageText.setString("PRESS ENTER TO START");
		messageText.setCharacterSize(75);
		messageText.setFillColor(sf::Color::White);

		score = 0;
		scoreText.setFont(font);
		scoreText.setString("Score = 0");
		scoreText.setCharacterSize(70);
		scoreText.setFillColor(sf::Color::Yellow);

		title.setFont(font);
		title.setString("TIMBER by MS");
		title.setCharacterSize(100);
		title.setFillColor(sf::Color::White);

		// time bar constructor
		timeBar.setSize(sf::Vector2f(timeBarStartWidth, timeBarHight));
		timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
		timeBar.setFillColor(sf::Color::Red);
		timeWidthPerSecond = timeBarStartWidth / timeRemaining;

		// time display
		timeDisplay.setFont(font);
		timeDisplay.setString("Time Remaining: ");
		timeDisplay.setCharacterSize(20);
		timeDisplay.setFillColor(sf::Color::White);

		// game time display
		gameTimeText.setFont(font);
		gameTimeText.setString("Game Time: 0.0");
		gameTimeText.setCharacterSize(70);
		gameTimeText.setFillColor(sf::Color::Yellow);
		
		// info text
		infoText.setString("ESC - Quit  ENTER - Continue");
		infoText.setFont(font);
		infoText.setCharacterSize(30);
		infoText.setFillColor(sf::Color::White);
	}

	void setPositions() {
		// create position in the center of the text to be reference point
		sf::FloatRect textRect = messageText.getLocalBounds();
		sf::FloatRect titleRect = title.getLocalBounds();
		messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
		//set text position considering that reference point is at the center of the text
		messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
		title.setPosition(1920 / 2.0f, 1080 / 2.0f - 200);
		timeDisplay.setPosition(1920 / 2.0f - 100, 1030);
		gameTimeText.setPosition(1350, 0);
		infoText.setPosition(700, 650);
	}

	void updateGameTime(sf::Time gameTime) {
		double gTime = gameTime.asSeconds();
		double rounded = std::floor((gTime * 100) + .5) / 100;
		std::stringstream ss;
		ss << "Game Time: " << rounded;
		gameTimeText.setString(ss.str());

	}

	void updateScore() {
		std::stringstream ss;
		ss << "Score = " << score;
		scoreText.setString(ss.str());
	}

	void updateTimeBar(sf::Time dt) {
		timeRemaining -= dt.asSeconds();
		timeBar.setSize(sf::Vector2f(timeWidthPerSecond * timeRemaining, timeBarHight));
	}

	void updateTimeShow() {
		std::stringstream ss;
		ss << "Time Remaining: " << int(timeRemaining)+1;
		timeDisplay.setString(ss.str());
	}

	void endOfTime() {
		title.setPosition(3000, title.getPosition().y);
		messageText.setString("Out of Time!");
		messageText.setFillColor(sf::Color::Red);
		messageText.setCharacterSize(100);
		sf::FloatRect textRect = messageText.getLocalBounds();
		messageText.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		messageText.setPosition(1920 / 2.0f, (1080 / 2.0f) - 100);
		timeDisplay.setString("Time Remaining: 0");
		
	}

	void deadMessage() {
		title.setPosition(3000, title.getPosition().y);
		messageText.setString("SQUASHED !");
		messageText.setCharacterSize(130);
		messageText.setFillColor(sf::Color::Red);
		sf::FloatRect textRect = messageText.getLocalBounds();
		messageText.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, (1080 / 2.0f) - 100);
	}
};