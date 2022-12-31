#pragma once
#include <SFML/Audio.hpp>

class Sounds {
public:
	sf::SoundBuffer chopBuffer;
	sf::SoundBuffer deadBuffer;
	sf::SoundBuffer outOfTimeBuffer;
	sf::Sound chop;
	sf::Sound dead;
	sf::Sound outOfTime;


	Sounds() {
		chopBuffer.loadFromFile("sound/chop.wav");
		chop.setBuffer(chopBuffer);

		deadBuffer.loadFromFile("sound/lost.wav");
		dead.setBuffer(deadBuffer);

		outOfTimeBuffer.loadFromFile("sound/out_of_time.wav");
		outOfTime.setBuffer(outOfTimeBuffer);
	}
};