///  BEE Class



#include <SFML/Graphics.hpp>

class Bee {
public:
	bool beeActive, beeDirection;
	float beeSpeed;
	sf::Texture textureBee;
	sf::Sprite spriteBee;

	Bee() {
		// create a Bee: texture + sprite + position + variables
		textureBee.loadFromFile("graphics/bee.png");
		spriteBee.setTexture(textureBee);
		spriteBee.setPosition(-100, 800);
		beeActive = false;
		beeSpeed = 0.0f;
		beeDirection = false;  // false ->left , true ->right
	}

    void beeMove(sf::Time dt) {
        //Bee movement logic
        if (!beeActive) {
            //how fast is the bee
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;

            // how hight is the bee
            srand((int)time(0) * 10);
            float hight = (rand() % 500) + 500;
            spriteBee.setPosition(2000, hight);
            beeActive = true;
        }
        else {
            //move bee to the left
            if (!beeDirection) {
                spriteBee.setPosition(
                    spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y
                );
                // iff bee reached left edge of the screen
                if (spriteBee.getPosition().x < -200) {
                    beeDirection = true;
                    spriteBee.setScale(-1.0f, 1.0f);
                }
            }
            else {
                // move bee to the right
                spriteBee.setPosition(
                    spriteBee.getPosition().x + (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y
                );
                // iff bee reached left edge of the screen 
                if (spriteBee.getPosition().x > 2000) {
                    beeActive = false;
                    beeDirection = false;
                    spriteBee.setScale(1.0f, 1.0f);
                }
            }
        }
    }

};