#include "PlayerController.h"
#include <Windows.h>

PlayerController::PlayerController(Player* &player, float boundsLeft, float boundsRight, int windowSize_x, int windowSize_y)
{
	{
		this->player = player;
		this->boundsLeft = boundsLeft;
		this->boundsRight = boundsRight;
		this->player->setPosition((boundsRight - 3.f * boundsLeft), (windowSize_y - this->player->getHeight()));
	}
}

bool PlayerController::onKeyPress(int windowBounds_y)
{
	bool idle = true;
	if (GetAsyncKeyState('A') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
	{
		// nach links bewegen
		if (this->player->getPosition_x() > boundsLeft)
		{
			this->player->setPlayerAnimation('L');
			this->player->moveLeft();
			idle = false;
		}
	}
	if (GetAsyncKeyState('D') && 0x8000) //|| GetAsyncKeyState(VK_RIGHT)) && 0x8000)
	{
		// nach rechts bewegen
		if (this->player->getPosition_x() + this->player->getWidth() < boundsRight)
		{
			this->player->setPlayerAnimation('R');
			this->player->moveRight();
			idle = false;
		}
	}
	if (GetAsyncKeyState('W') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
	{
		// nach oben bewegen
		if (this->player->getPosition_y() > 0)
		{
			this->player->setPlayerAnimation('U');
			this->player->moveUp();
			idle = false;
		}
	}
	if (GetAsyncKeyState('S') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
	{
		// nach unten bewegen
		if (this->player->getPosition_y() + this->player->getHeight() < windowBounds_y)
		{
			this->player->setPlayerAnimation('D');
			this->player->moveDown();
			idle = false;
		}
	}
	//if (idle)
	//{
	//	this->player->getCurrentAnimation();
	//}
	return !idle;
}

//void PlayerController::playerSetup(Player* p,float windowSize_y)
//{
//	p->setPosition(3 * boundsLeft, windowSize_y - this->player->getHeight());
//}
