#pragma once

#include <SFML/Graphics.hpp>
#include "Side.h"


class Branches {
public:
	static const int NUM_BRANCHES = 6;
	sf::Texture textureBranch;
	sf::Sprite branch[NUM_BRANCHES];
	//enum class side {LEFT, RIGHT, NONE};
	// empty array for holding positions of 6 branches
	Side branchPosition[NUM_BRANCHES];


	Branches() {
		textureBranch.loadFromFile("graphics/branch.png");
		initBranches();
	}

	void initBranches() {
		// constructor for 6 branches
		for (int i=0; i < 6; i++) {
			branch[i].setTexture(textureBranch);
			branch[i].setPosition(-2000, -2000);
			branch[i].setOrigin(220, 20);
		}
	}

	void updateBranches() {
		for (int i = 0; i < NUM_BRANCHES; i++) {
			float height = i * 180;
			// redistribue branches
			if (branchPosition[i] == Side::LEFT) {
				branch[i].setPosition(610, height);
				branch[i].setRotation(180);
			}
			else if (branchPosition[i] == Side::RIGHT)
			{
				branch[i].setPosition(1330, height);
				branch[i].setRotation(0);
			}
			// hide all branches at the begining
			else {
				branch[i].setPosition(3000, height);

			}
		}
	}

	void moveBranches(int seed) {
		// use array with branches 

		// move one space down
		for (int i = NUM_BRANCHES - 1; i > 0; i--) {
			branchPosition[i] = branchPosition[i - 1];
		}
		
		// adding new branch at position 0 in array
		srand((int)time(0) + seed);
		int r = (rand() % 6);

		switch (r) {
		case 0:
			branchPosition[0] = Side::RIGHT;
			break;
		case 1:
			branchPosition[0] = Side::LEFT;
			break;
		default:
			branchPosition[0] = Side::NONE;
			break;
		}
	}
};

// p.124