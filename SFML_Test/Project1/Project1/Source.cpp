#include "Game.h"
#include "Player.h"
#include "PlayerController.h"
//#include <Windows.h>
#include <SFML\graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!"); // 1024, 768
	window.setFramerateLimit(120);
	float boundsLeft = window.getSize().x / 8.f;
	float boundsRight = window.getSize().x - boundsLeft;
	int tick = 0;
	//sf::Texture texture;
	sf::Texture myTexture;
	Player* player = new Player();
	//player->initPlayer(myTexture);
	Game* game = new Game(player, myTexture);
	//game->loadSpriteIntoStack("Player", player->initPlayer(myTexture));

	PlayerController* controller = new PlayerController(player, boundsLeft, boundsRight, window.getSize().x, window.getSize().y);
	//controller->playerSetup(player, window.getSize().y - player->getHeight());
	// Position Spieler 
	//Hintergründe
	// Gleichen Hintergrund zwei mal initialisieren und hintereinander durchscrollen
	// Positionen zurücksetzen (hinten anstellen), wenn sie zu weit aus dem Bild laufen
	sf::Texture backGround;
//	backGround.loadFromFile("..\\Ressources\\img\\tile.png");
	backGround.loadFromFile("..\\Ressources\\img\\map.png");
	sf::Sprite myBackGround, myBackGround2;

	// Hintergründe auf Bildschirmgröße skalieren
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;
	TextureSize = backGround.getSize();
	WindowSize = window.getSize();

	float ScaleX = (float)(WindowSize.x*3/4) / TextureSize.x;
	//float ScaleY = (float)WindowSize.y / TextureSize.y;
	float ScaleY = 1.f;

	myBackGround.setTexture(backGround);
	myBackGround.setScale(ScaleX, ScaleY);
	myBackGround2.setScale(ScaleX, ScaleY);
	myBackGround.setPosition(boundsLeft, -myBackGround.getGlobalBounds().height + window.getSize().y);

	myBackGround2.setTexture(backGround);
	myBackGround2.setPosition(boundsLeft, -myBackGround2.getGlobalBounds().height);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game->updatePlayer(controller->onKeyPress(window.getSize().y));
		//window.clear(sf::Color::Black);
		/*Hintergründe durchscrollen*/
		if (myBackGround.getPosition().y > window.getSize().y) myBackGround.setPosition(myBackGround.getPosition().x, -myBackGround.getGlobalBounds().height);
		if (myBackGround2.getPosition().y > window.getSize().y) myBackGround2.setPosition(myBackGround2.getPosition().x, -myBackGround.getGlobalBounds().height);
		//mySpriteShadow.setPosition(mySprite.getPosition().x + 7, mySprite.getPosition().y + 7);
		if (tick % 10 == 0)
		{
			myBackGround.setPosition(myBackGround.getPosition().x, myBackGround.getPosition().y + 1);
			myBackGround2.setPosition(myBackGround2.getPosition().x, myBackGround2.getPosition().y + 1);
		}
		window.draw(myBackGround);
		//window.draw(myBackGround2);
		game->DrawStackOfSprites(window);
		window.display();
		tick++;
	}
	return 0;
}