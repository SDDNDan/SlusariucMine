// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;
int main()
{
	RenderWindow renderWindow(VideoMode(640, 480),"MineSweeper");
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
			case Event::Resized:
				cout << eveniment.size.height << " " << eveniment.size.width << endl;
				break;
			case Event::TextEntered:
				cout << eveniment.text.unicode;
				break;

			}
		}
	}
}

