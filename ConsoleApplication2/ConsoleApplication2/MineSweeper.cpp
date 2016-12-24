// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow renderWindow(VideoMode(1024, 860),"MineSweeper");
	Sprite Start;
	Texture ButonulStart;
	ButonulStart.loadFromFile("Start_button_red.png");
	ButonulStart.setSmooth(true);
	Start.setTexture(ButonulStart);
	Start.setScale(0.5f, 0.5f);
	Start.setPosition(Vector2f(440,640));
	
	while (renderWindow.isOpen())
	{  
		Event eveniment;
		while (renderWindow.pollEvent(eveniment))
		{
			
			switch (eveniment.type)
			{
			case Event::Closed:
					renderWindow.close();
					break;
			
			}
			renderWindow.draw(Start);
			renderWindow.display();
		}
	}
}

