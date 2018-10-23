#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	// Spielfigur
	sf::Texture myTexture;
	myTexture.loadFromFile("..\\Ressources\\img\\testpng.png");
	sf::Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setScale(0.2, 0.2);
	//Hintergründe
	// Gleichen Hintergrund zwei mal initialisieren und hintereinander durchscrollen
	// Positionen zurücksetzen (hinten anstellen), wenn sie zu weit aus dem Bild laufen
	sf::Texture backGround;
	sf::Texture backGround2;
	backGround.loadFromFile("..\\Ressources\\img\\map_tile.jpg");
	backGround2.loadFromFile("..\\Ressources\\img\\map_tile2.jpg");
	sf::Sprite myBackGround, myBackGround2;
	myBackGround2.scale(600,600);
	myBackGround.setTexture(backGround);
	myBackGround2.setTexture(backGround2);
	myBackGround.setScale(0.6f, 1.f);
	myBackGround.setPosition(125, 0);
	myBackGround2.setScale(0.6f, 1.f);
	myBackGround2.setPosition(125, -myBackGround2.getGlobalBounds().height);// -myBackGround.getGlobalBounds().height);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		/*Hintergründe durchscrollen*/
		//if (myBackGround.getPosition().y > 600) myBackGround.setPosition(myBackGround.getPosition().x, -myBackGround.getGlobalBounds().height);
		//if (myBackGround2.getPosition().y > 600) myBackGround2.setPosition(myBackGround2.getPosition().x, -myBackGround.getGlobalBounds().height);
		if (GetAsyncKeyState('W') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
		{
			// nach links bewegen
			mySprite.setPosition(mySprite.getPosition().x, mySprite.getPosition().y - 1);
		}
		if (GetAsyncKeyState('A') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
		{
			// nach links bewegen
			mySprite.setPosition(mySprite.getPosition().x - 1, mySprite.getPosition().y);
		}
		if (GetAsyncKeyState('D') && 0x8000) //|| GetAsyncKeyState(VK_RIGHT)) && 0x8000)
		{
			// nach rechts bewegen
			mySprite.setPosition(mySprite.getPosition().x + 1, mySprite.getPosition().y);
		}
		if (GetAsyncKeyState('S') && 0x8000) //|| GetAsyncKeyState(VK_LEFT)) && 0x8000)
		{
			// nach links bewegen
			mySprite.setPosition(mySprite.getPosition().x, mySprite.getPosition().y + 1);
		}
		//myBackGround.setPosition(myBackGround.getPosition().x, myBackGround.getPosition().y + 1);
		myBackGround2.setPosition(myBackGround2.getPosition().x, myBackGround2.getPosition().y + 1);
		window.draw(myBackGround);
		window.draw(myBackGround2);
		window.draw(mySprite);
		window.display();
	}
	return 0;
}