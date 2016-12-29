// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace sf;
using namespace std;
int rezx, rezy;
int main()
{
	
	
	rezx = 1024;
	rezy = 860;
	RenderWindow renderWindow(VideoMode(rezx, rezy), "MineSweeper");
	Sprite Start;
	Texture ButonulStart;
	ButonulStart.loadFromFile("Start_button_red.png");
	ButonulStart.setSmooth(true);
	Start.setTexture(ButonulStart);
	Start.setScale(0.7f, 0.7f);
	Start.setPosition(Vector2f(420, 660));
	Sprite Background;
	Texture Backgroundtext;
	Backgroundtext.loadFromFile("Background.png");
	Backgroundtext.setSmooth(true);
	Background.setTexture(Backgroundtext);
	Sprite joc[30][30];
	Texture patrat;
	patrat.loadFromFile("patrat.png");
	patrat.setSmooth(true);
	int n;
	cin >> n;
	int Okpentrustart = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			joc[i][j].setTexture(patrat);
			joc[i][j].setPosition(Vector2f(1800/n+30 * i,1500/n+30 * j));
	     }
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
			case Event::MouseButtonPressed:
				if (eveniment.mouseButton.x >= Start.getPosition().x&&eveniment.mouseButton.y >= Start.getPosition().y)
					if (eveniment.mouseButton.x <= Start.getPosition().x + 120 && eveniment.mouseButton.y <= Start.getPosition().y + 120)
				{cout << eveniment.mouseButton.x << " " << eveniment.mouseButton.y;
				cout << endl << Start.getPosition().x << " " << Start.getPosition().y;
					cout << "Da"<<endl;
				Okpentrustart = 1;	}
				break;
			}

			
			
			renderWindow.draw(Background);
			renderWindow.draw(Start);
			if (Okpentrustart == 1)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						renderWindow.draw(joc[i][j]);
					}
			renderWindow.display();
		
			



		}
	}
	
	
}

