#pragma once
/*
   Timber game
*/

#include <sstream>
#include <SFML/Graphics.hpp>
#include "Bee.h"
#include "cloud.h"
#include "backgroud.h"
#include "tree.h"
#include "hud.h"
#include "Branches.h"
#include "Player.h"
#include "Side.h"
#include "sounds.h"

class Timber {
private:
    // Initialize Sprites
    Backgroud background;
    Bee bee;
    Cloud cloud;
    Tree tree;
    Hud hud;
    Branches branches;
    Player1 player1;
    Sounds sound;
    // Variables
    sf::Clock clock;
    sf::Clock gameTimeStart;
    sf::Time dt;
    sf::Time gameTimer;
    bool pause = true;
    bool acceptInput = false;

public:
    Timber() {
        //constructor
        startGame();
    }

    int startGame() {
        // create video model object
        sf::VideoMode videomode(1920, 1080);
        // create and open new window
        sf::RenderWindow window(videomode, "Timber game", sf::Style::Fullscreen);

        // prepare positioning of the on screen messages
        hud.setPositions();

        // Game Starts
        while (window.isOpen()) {
            // start timer
            gameTimer = gameTimeStart.getElapsedTime();
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyReleased && !pause) {
                    // released key logic
                    acceptInput = true;

                    // hide axe
                    player1.spriteAxe.setPosition(2000, player1.spriteAxe.getPosition().y);
                }
            }

            // Handle the players input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            };

            // when ENTER pressed
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                pause = false;
                // reset score and time
                hud.score = 0;
                hud.timeRemaining = 6;
                hud.messageText.setPosition(2000, hud.messageText.getPosition().y);

                // reset all branches ,set player, remove RIP
                for (int i = 0; i < branches.NUM_BRANCHES;i++) {
                    branches.branchPosition[i] = Side::NONE;
                }
                player1.spriteRIP.setPosition(675, 2000);
                player1.playerSprite.setPosition(580, 720);
                acceptInput = true;
            };

            if (acceptInput) {
                // left key logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

                };

                // right key logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    player1.playerSide = Side::RIGHT;
                    hud.score++;
                    hud.timeRemaining += (2 / hud.score) + .15;
                    player1.spriteAxe.setPosition(player1.AXE_POSITION_RIGHT,
                        player1.spriteAxe.getPosition().y);
                    player1.playerSprite.setPosition(1200, 720);
                    branches.moveBranches(hud.score);     // <---- MOVE BRANCHES
                    tree.spriteLog.setPosition(810, 720);
                    tree.logSpeedX = -5000;
                    tree.logActive = true;
                    sound.chop.play();

                    acceptInput = false;
                };

                // right key logic
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    player1.playerSide = Side::LEFT;
                    hud.score++;
                    hud.timeRemaining += (2 / hud.score) + .15;
                    player1.spriteAxe.setPosition(player1.AXE_POSITION_LEFT,
                        player1.spriteAxe.getPosition().y);
                    player1.playerSprite.setPosition(580, 720);
                    branches.moveBranches(hud.score);       // <---- MOVE BRANCHES
                    tree.spriteLog.setPosition(810, 720);
                    tree.logSpeedX = 5000;
                    tree.logActive = true;
                    sound.chop.play();
                    acceptInput = false;
                };
            }
            
            if (!pause) {
                // this will restart time after 6sec when coming out of pause
                // init timer
                dt = clock.restart();
                // Update the scene
                // -------------------------
                hud.updateGameTime(gameTimer);
                hud.updateTimeBar(dt);
                hud.updateTimeShow();
                // run out of time function
                
                if (hud.timeRemaining <= 0.0f) {
                    pause = true;
                    hud.endOfTime();
                    sound.outOfTime.play();
                }
                
                //move bee - logic
                bee.beeMove(dt);
                // move cloud - logic           
                cloud.cloudMove(dt);
                branches.updateBranches();     // <---- UPDATE BRANCHES
                
                // check if log been hit and act
                if (tree.logActive) {
                    tree.moveLog(dt);
                }

                // check for player collision
                if (branches.branchPosition[5] == player1.playerSide) { 
                    pause = true;
                    acceptInput = false;
                    player1.spriteRIP.setPosition(525, 760);
                    player1.playerSprite.setPosition(2000, 660);
                    sound.dead.play();
                    // generate message
                    hud.deadMessage();
                    gameTimeStart.restart();

                }
            }

            // Draw the scene
            // Clear everything from the last frame
            window.clear();
            // Draw game scene 
            window.draw(background.spriteBackground);
            window.draw(cloud.spriteCloud1);
            window.draw(cloud.spriteCloud2);
            window.draw(cloud.spriteCloud3);
            for (int i = 0;i < branches.NUM_BRANCHES; i++) {
                window.draw(branches.branch[i]);
            }
            window.draw(tree.spriteTree);
            window.draw(bee.spriteBee);
            hud.updateScore();
            window.draw(hud.gameTimeText);
            window.draw(hud.scoreText);

            window.draw(hud.timeBar);
            window.draw(hud.timeDisplay);
            window.draw(player1.playerSprite);
            window.draw(player1.spriteAxe);
            window.draw(player1.spriteRIP);
            window.draw(tree.spriteLog);

            // Game paused at the begining
            if (pause) {
                window.draw(hud.messageText);
                window.draw(hud.title);
                window.draw(hud.infoText);
            };

            // render window 
            window.display();
        };
        return 0;
    }
};

int main()
{
    // start game
    Timber x;
}

