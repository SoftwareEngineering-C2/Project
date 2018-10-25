#pragma once
#include "Player.h"

class Player;

class PlayerController{
private: 
	Player* player;
	float boundsLeft;
	float boundsRight;
public:
	PlayerController(Player* &player, float boundsLeft, float boundsRight, int windowSize_x, int windowSize_y);
	void onKeyPress(int);
	void playerSetup(Player*,float);
};