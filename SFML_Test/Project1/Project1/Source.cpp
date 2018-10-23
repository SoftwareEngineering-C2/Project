#include <SFML\graphics.hpp>
#include <Windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFML works!"); // 1024, 768
	int renderStart_x = window.getSize().x / 8;
	int renderEnd_x = window.getSize().x - renderStart_x;
	int tick = 0;
	// Spielfigur
	sf::Texture myTexture;
	myTexture.loadFromFile("..\\Ressources\\img\\testpng.png");
	sf::Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setScale(0.2f, 0.2f);
	//Hintergründe
	// Gleichen Hintergrund zwei mal initialisieren und hintereinander durchscrollen
	// Positionen zurücksetzen (hinten anstellen), wenn sie zu weit aus dem Bild laufen
	sf::Texture backGround;
	backGround.loadFromFile("..\\Ressources\\img\\tile.png");// , sf::IntRect(renderStart_x, 0, renderEnd_x, window.getSize().y));
	sf::Sprite myBackGround, myBackGround2;

	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.
	TextureSize = backGround.getSize(); //Get size of texture.
	WindowSize = window.getSize();             //Get size of window.

	float ScaleX = (float)(WindowSize.x*3/4) / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

	myBackGround.setTexture(backGround);
	myBackGround.setScale(ScaleX, ScaleY);      //Set scale.  
	myBackGround2.setScale(ScaleX, ScaleY);      //Set scale.  
	myBackGround.setPosition(renderStart_x, 0);

	myBackGround2.setTexture(backGround);
	myBackGround2.setPosition(renderStart_x, -myBackGround2.getGlobalBounds().height);

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
		if (myBackGround.getPosition().y > window.getSize().y) myBackGround.setPosition(myBackGround.getPosition().x, -myBackGround.getGlobalBounds().height);
		if (myBackGround2.getPosition().y > window.getSize().y) myBackGround2.setPosition(myBackGround2.getPosition().x, -myBackGround.getGlobalBounds().height);
		if (tick % 15 == 0)
		{
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
		}
		if (tick % 15 == 0)
		{
			myBackGround.setPosition(myBackGround.getPosition().x, myBackGround.getPosition().y + 1);
			myBackGround2.setPosition(myBackGround2.getPosition().x, myBackGround2.getPosition().y + 1);
		}
		window.draw(myBackGround);
		window.draw(myBackGround2);
		window.draw(mySprite);
		window.display();
		tick++;
	}
	return 0;
}