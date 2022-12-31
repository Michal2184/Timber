


#include <SFML/Graphics.hpp>


class Cloud {
public:
	sf::Texture textureCloud;
	sf::Sprite spriteCloud1, spriteCloud2, spriteCloud3;

	bool cloud1Active, cloud2Active, cloud3Active;
	float cloud1Speed, cloud2Speed, cloud3Speed;

	Cloud() {
        // create Clouds x3 : texture + sprite + position + variables
        textureCloud.loadFromFile("graphics/cloud.png");
        spriteCloud1.setTexture(textureCloud);
        spriteCloud2.setTexture(textureCloud);
        spriteCloud3.setTexture(textureCloud);
        spriteCloud1.setPosition(-500, 0);
        spriteCloud2.setPosition(-500, 250);
        spriteCloud3.setPosition(-500, 500);

        cloud1Speed = 0.0f;
        cloud2Speed = 0.0f;
        cloud3Speed = 0.0f;
        cloud1Active = false;
        cloud2Active = false;
        cloud3Active = false;
	}

    void cloudMove(sf::Time dt) {
        // cloud movment logic
        if (!cloud1Active) {
            // cloud speed
            srand((int)time(0) * 10);
            cloud1Speed = (rand() % 200);

            //cloud hight
            srand((int)time(0) * 10);
            float height = (rand() % 150);

            spriteCloud1.setPosition(-200, height);
            cloud1Active = true;
        }
        else {
            spriteCloud1.setPosition(
                (spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds())),
                spriteCloud1.getPosition().y
            );
            if (spriteCloud1.getPosition().x > 1920) cloud1Active = false;
        }

        if (!cloud2Active) {
            // cloud speed
            srand((int)time(0) * 20);
            cloud2Speed = (rand() % 200);

            //cloud hight
            srand((int)time(0) * 20);
            float height = (rand() % 300);

            spriteCloud2.setPosition(-200, height);
            cloud2Active = true;
        }
        else {
            spriteCloud2.setPosition(
                (spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds())),
                spriteCloud2.getPosition().y
            );
            if (spriteCloud2.getPosition().x > 1920) cloud2Active = false;
        }

        if (!cloud3Active) {
            // cloud speed
            srand((int)time(0) * 50);
            cloud3Speed = (rand() % 200);

            //cloud hight
            srand((int)time(0) * 30);
            float height = (rand() % 450);

            spriteCloud3.setPosition(-200, height);
            cloud3Active = true;
        }
        else {
            spriteCloud3.setPosition(
                (spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds())),
                spriteCloud3.getPosition().y
            );
            if (spriteCloud3.getPosition().x > 1920) cloud3Active = false;
        }
    }
};